#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;
int main()
{
	int i,j,count(0),num(-1),num1(0),pos(-1);
	string s,s1,s2,S;
	getline(cin,S);
	getline(cin,s);
	for (i=0;i<S.size();i++) S[i]=tolower(S[i]);
	s1=s;
	for (i=0;i<s1.size();i++) s1[i]=tolower(s1[i]);
	stringstream a(s1);
	while (a>>s2)
	{
		num++;
		if (S==s2)
		{
			count++;
			if (pos==-1)
			{
				for (i=0;i<s1.size();i++)
				{
					if (s1[i]==' ') num1++;
					if (num1==num) break;
				}
				pos=(i==0?0:i+1);
			}
		}
	}
	if (pos==-1&&count==0) cout<<"-1"<<endl;
	else cout<<count<<' '<<pos<<endl;
	return 0;
}

