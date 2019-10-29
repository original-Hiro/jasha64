#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
bool isprime(int n)
{
	if (n==0||n==1) return false;
	if (n==2) return true;
	int i;
	for (i=2;i<=sqrt(i)+1;i++) if (n%i==0) return false;
	return true;
}
void process(string s)
{
	int i,num[123]={0},maxnum(0),minnum(0),ans;
	for (i=0;i<s.size();i++)
		num[s[i]]++;
	for (i=97;i<=122;i++)
		if (num[i]!=0)
		{
			maxnum=max(maxnum,num[i]);
			minnum=min(minnum,num[i]);
		}
	ans=maxnum-minnum;
	if (isprime(ans)) cout<<"Lucky Word"<<endl<<ans<<endl;
	else cout<<"No Answer"<<endl<<"0"<<endl;
}
int main()
{
	string s;
	cin>>s;
	process(s);
	return 0;
}

