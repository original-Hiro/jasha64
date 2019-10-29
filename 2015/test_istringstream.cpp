#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	int c,sum(0);
	string s;
	getline(cin,s);
	istringstream a(s);
	while (a>>c) sum+=c;
	cout<<sum<<endl;
	return 0;
}

