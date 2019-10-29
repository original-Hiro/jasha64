#include<iostream>
#include<set>
#include<iterator>
using namespace std;
multiset<int> a;
multiset<int>::iterator I,P1,P2;
int main()
{
	int n,i,cache,ans(0);
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>cache;
		a.insert(cache);
	}
	for (I=a.begin();I!=a.end();I++)
	{
		P1=I;
		cache=*I+*(++I);
		P2=I;
		ans+=cache;
		a.erase(P1);
		a.erase(P2);
		a.insert(cache);
	}
	cout<<ans<<endl;
	return 0;
}

