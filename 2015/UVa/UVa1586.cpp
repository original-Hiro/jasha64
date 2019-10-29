#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;
int main()
{
	int i,cc,T;
	const double Mc(12.01),Mh(1.008),Mo(16.00),Mn(14.01);
	double Mr;
	char cache(0);
	map<char,int> pos,num;
	string s;
	cin>>T;
	while (T--)
	{
		cin>>s;
		for (i=0;i<s.size();i++)
		{
			if (isalpha(s[i]))
			{
				if (cache)
				{
					if (pos[cache]==i) cc=1;
					else {
						istringstream ss(s.substr(pos[cache],i-pos[cache]));
						ss>>cc;
					}
					num[cache]+=cc;
					pos[cache]=0;
					cache=0;
				}
				cache=s[i];
				pos[cache]=i+1;
			}
		}
		if (cache)
		{
			if (pos[cache]==i) cc=1;
			else {
				istringstream ss(s.substr(pos[cache],i-pos[cache]));
				ss>>cc;
			}
			num[cache]+=cc;
		}
		Mr=num['C']*Mc+num['H']*Mh+num['O']*Mo+num['N']*Mn;
//		cout<<"N(C)="<<num['C']<<" N(H)="<<num['H']<<" N(O)="<<num['O']<<" N(N)="<<num['N']<<endl;
		printf("%.3f\n",Mr);
		num['C']=num['H']=num['O']=num['N']=Mr=cache=0;
	}
	return 0;
}

