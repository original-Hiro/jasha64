#include<iostream>
using namespace std;
template <class T>
inline void tension (T &a,const T &b)
{
	if (b>a) a=b;
}
int main()
{
	int a,b;
	cin>>a>>b;
	tension(a,b);
	cout<<a<<endl;
	return 0;
}

