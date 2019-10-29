#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,j,n;
	string s;
	cin>>n;
	while (n--)
	{
		cin>>s;
		for (i=1;i<s.size();i++)
		{
			if (s.size()%i) continue;
			for (j=i;j<s.size();j++) if (s[j]!=s[j%i]) break;
			if (j==s.size()) break;
		}
		cout<<i<<endl;
		if (n) cout<<endl;
	}
	return 0;
}

