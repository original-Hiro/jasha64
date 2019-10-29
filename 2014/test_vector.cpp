#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
	int n,i,cache;
	vector<int> s;
	vector<int>::iterator I;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>cache;
		s.push_back(cache);
	}
	cout<<"size:"<<s.size()<<endl<<"contents:";
	for (i=0;i<n;i++) cout<<s[i]<<' ';
	cout<<endl;
	while (cin>>cache,s.size()>0)
	{
		I=s.begin()+cache;
		s.erase(I);
		cout<<"size:"<<s.size()<<endl<<"contents:";
		for (i=0;i<s.size();i++) cout<<s[i]<<' ';
		cout<<endl;
	}
	cout<<endl;
	return 0;
}

