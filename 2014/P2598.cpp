#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,a[1005],i,s[1005],cache,top(0);
	fill(s,s+1005,0x7fffffff);
	cin>>n;
	for (i=0;i<n;i++) cin>>a[i];
	for (i=0;i<n;i++)
	{
		cache=lower_bound(s,s+n,a[i])-s;
		s[cache]=a[i];
		if (cache>=top) top++;
	}
	cout<<top<<endl;
	return 0;
}

