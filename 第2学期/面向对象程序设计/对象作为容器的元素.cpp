//未定义构造函数的结构体对象作为容器的元素被创建时，其中的内置数据类型是会得到初始化的 
#include <iostream>
#include <vector>
using namespace std;

struct P
{
	int a, b;
};

int main()
{
	vector<P> v;
	
	v.resize(10);
	
	for (int i = 0; i < 10; i++) cout << '(' << v[i].a << ',' << v[i].b << ')' << ' ';
	cout << endl;
	
	return 0;
}

