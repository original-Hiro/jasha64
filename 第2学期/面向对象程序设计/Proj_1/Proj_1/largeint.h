#pragma once
#include <vector>

class largeint
{
public:
	typedef std::vector<int>::size_type size_type;
	//类型定义

	largeint();
	largeint(int n);
	//构造函数

	size_type size() const {return v.size() - 1;}
	//定义变量用来保存某个特定数据结构的大小的时候，应使用该数据结构的相应类型
	//原则上，不需要修改类对象内部内容的成员函数均应加const限定符，以便该类const对象可以调用 
	
private:
	std::vector<int> v;
	//用vector保存大整数的各个位，其中第一位为符号位（0表示非负，1表示负） 
	//第二位开始，逆序保存大整数（即第二位为个位，第三位为十位，依次类推） 
};

