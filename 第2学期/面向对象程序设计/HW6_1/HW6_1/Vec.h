#pragma once
#include <cstddef>
#include <memory>

template <class T>
class Vec
{
public:
	//类型定义
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	//构造函数
	Vec() { create(); }
	explicit Vec(size_type n, const T& t = T()) { create(n, t);	}
	//explicit关键字的作用：阻止隐式调用构造函数，防止不自然的隐式类型转换或是等号初始化时的定义冲突
	//定义变量用来保存某个特定数据结构的大小的时候，应使用该数据结构的相应类型

	//复制、赋值、析构函数
	Vec(const Vec& v) { create(v.begin(), v.end()); } //因为复制函数中已经包含了产生参数复件的过程，这里的参数声明成引用
	Vec& operator = (const Vec&);
	~Vec() { uncreate(); }

	//索引运算符重载
	T& operator [] (size_type i) { return data[i]; }
	const T& operator [] (size_type i) const { return data[i]; }
	//定义变量用来保存某个特定数据结构的大小的时候，应使用该数据结构的相应类型
	//应该声明两类，其中一个是const类型，以便该类常量可以调用

	//成员函数：添加元素
	void push_back(const T& t)
	{
		if (avail == limit) grow();
		unchecked_append(t);
	}
	//参数声明成引用类型，是为了在T类型非常复杂的时候防止耗时间复制

	//成员函数：大小
	size_type size() const { return avail - data; }
	//原则上，不改变对象内部状态的成员函数都应加const限定，以便该类常量对象可以调用

	//成员函数：是否为空
	bool empty() const { return data == NULL; }

	//成员函数：清除当前的Vec，恢复到初始状态
	void clear() { uncreate(); create(); }

	//成员函数：首地址、越界地址
	iterator begin() { return data; }
	const_iterator begin() const { return data; }
	iterator end() { return avail; }
	const_iterator end() const { return avail; }

private:
	//成员变量：首地址、元素越界、内存越界
	iterator data, avail, limit;

	//成员变量：内存分配
	std::allocator<T> alloc;

	//私有成员函数（类的实现细节）
	//分配内存和初始化数组
	void create() { data = avail = limit = NULL; }
	void create(size_type n, const T& val)
	{
		data = alloc.allocate(n); //分配能且仅能容纳n个T类型变量的空间（未初始化的），返回首地址
		limit = avail = data + n;
		std::uninitialized_fill(data, limit, val); //用给定的值填充未初始化的一段该类型空间，没有返回值
	}
	void create(const_iterator b, const_iterator e)
	{
		data = alloc.allocate(e - b);
		limit = avail = std::uninitialized_copy(b, e, data);
		//将给定的一段区间复制填充到给定的首地址代表的另一段空间，返回后一段空间的越界指针
	}
	//擦去数组的元素，然后释放内存
	void uncreate();
	//support functions for push_back
	void grow();
	void unchecked_append(const T& val)
	{
		alloc.construct(avail++, val); //在给定的未初始化空间中建立值为val的相应类型变量
	} //不检查是否还有可用空间，直接把元素添加到末尾
};
//结构体和类的最后都要加分号（程序结构变得复杂时容易忘记）

//模板类的定义和实现均保存于头文件（否则编译器报错：不可识别的模板声明）
template <class T>
Vec<T>& Vec<T>::operator= (const Vec& rhs)
{
	if (&rhs == this) return *this; //自我赋值判断
	uncreate(); //清除被赋值对象
	create(rhs.begin(), rhs.end()); //将等号右边对象的值复制给等号左边对象
	return *this; //返回被赋值对象自身的引用
}
//在类的生存空间，可以省略模板类型参数T（隐式包含）；在类的生存空间外，必须显式说明
//此函数参数列表中，由于前面的函数名已经加了类名限定，所以不再需要加<T>
template <class T>
void Vec<T>::uncreate()
{
	if (data) //由于deallocate函数要求参数必须是非空指针，所以要判断data是否为空
	{
		iterator i = avail;
		while (i != data) alloc.destroy(--i); //擦去迭代器指向的该类型变量，留下未初始化的空间
		//经测试，此处也可以正序释放内存。选择逆序是为了和上面的create函数产生直观的相反效果。
		alloc.deallocate(data, limit - data); //释放给定的一段地址指向的空间
	}
	//重置指针，表示现在Vec已经是空的了
	data = avail = limit = NULL;
}
template <class T>
void Vec<T>::grow()
{
	//为了提高工作效率，申请空间时，我们申请当前大小2倍的空间备用，而不是每次都申请刚好需要的容量的空间
	size_type new_size = std::max(2 * (limit - data), (ptrdiff_t)1);

	//申请新的一段空间，把当前的所有数据复制到新空间
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	//释放旧的空间
	uncreate();

	//把指针改为指向新申请的空间
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}
