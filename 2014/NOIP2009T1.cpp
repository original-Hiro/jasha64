#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,j;
	string a,b,p;
	char f[91]={0};
	cin>>a>>b>>p;
	for (i=0;i<a.size();i++) f[a[i]]=b[i];
	for (i=65;i<=90;i++)
		if (f[i]==0)
		{
			cout<<"Failed"<<endl;
			return 0;
		}
	for (i=65;i<=90;i++)
		for (j=65;j<=90;j++)
			if (i!=j&&f[i]==f[j])
				{
					cout<<"Failed"<<endl;
					return 0;
				}
	for (i=0;i<p.size();i++) cout<<f[p[i]];
	cout<<endl;
	return 0;
}

