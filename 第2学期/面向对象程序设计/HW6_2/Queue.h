#pragma once
#include <cstddef>
#include <iostream>

template <class T>
class Queue
{
public:
	typedef std::ptrdiff_t size_type; //类型定义

	Queue() :head(NULL), rear(NULL), siz(0)
	{
		std::cout << "default constructor called." << std::endl; //按照格式要求，输出调用提示语句
	} //default constructor
	Queue(const Queue& q)
	{
		std::cout << "copy constructor called." << std::endl;
		copyLink(q.head);
	} //copy constructor
	~Queue()
	{
		std::cout << "destructor called." << std::endl;
		freeLink();
	} //destructor
	Queue& operator= (const Queue&); //assignment operator

	bool enQueue(T);	//进队
	bool deQueue();		//出队

	T front() const { return head->val; } //返回队首元素的值 
	T back() const { return rear->val; } //返回队尾元素的值 

	size_type size() const { return siz; } //大小

	bool isEmpty(void) const { return head == NULL; } //判断队列是否为空 
	bool isFull(void) const { return size() >= 50; } //判断队列是否已满

	void output(void) const; //输出队列 

private:
	struct node{
		T val;
		node* next;
		node(T v = T()) :val(v), next(NULL) {}
	}*head, *rear; //队列首尾元素指针 
	size_type siz;

	//内存管理函数 
	void copyLink(node *);	//复制已有链表 
	void freeLink(); //释放已有链表所占空间 
};

template <class T>
Queue<T>& Queue<T>::operator= (const Queue& rhs)
{
	std::cout << "operator=() called." << std::endl;
	if (&rhs == this) return *this; //防止自我赋值
	freeLink();
	copyLink(rhs.head);
	return *this;
}
template <class T>
bool Queue<T>::enQueue(T val)
{
	if (isFull()) return false;
	node* new_rear = new node(val);
	if (isEmpty()) head = new_rear;
	else rear->next = new_rear;
	rear = new_rear;
	siz++;
	return true;
}
template <class T>
bool Queue<T>::deQueue()
{
	if (isEmpty()) return false;
	node* new_head = head->next;
	delete head; head = new_head;
	siz--;
	return true;
}
template <class T>
void Queue<T>::output() const
{
	int cnt = 0; //当前行已经输出了多少个元素，每10个换一行
	for (node* it = head; it != NULL; it = it->next)
	{
		std::cout << it->val << ' '; ++cnt;
		if (cnt == 10) { std::cout << std::endl; cnt = 0; }
	}
	std::cout << std::endl;
}
template <class T>
void Queue<T>::copyLink(node* rhs)
{
	//逐个申请空间并复制值
	head = new node(rhs->val);
	const node* ci = rhs->next;
	node* i = head;
	while (ci != NULL)
	{
		i->next = new node(ci->val);
		i = i->next; ci = ci->next;
	}
	rear = i;
}
template <class T>
void Queue<T>::freeLink()
{
	//逐个释放申请到的空间
	node* i = head;
	while (i != NULL)
	{
		node* j = i->next;
		delete i;
		i = j;
	}
	head = rear = NULL;
}

