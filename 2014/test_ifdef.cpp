#ifdef LOCAL
#include<iostream>
#else
#include<fstream>
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<a+b<<endl;
	return 0;
}

