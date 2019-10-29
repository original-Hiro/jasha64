#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
struct point
{
	int data;
	vector<int> connected;
} p[200005];
int main()
{
	int n,a,b,i;
	long long ans(0),sum(0),cache;
	const int M(10007);
	vector<int>::iterator I1,I2;
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>a>>b;
		p[a].connected.push_back(b);
		p[b].connected.push_back(a);
	}
	for (i=1;i<=n;i++) cin>>p[i].data;
	for (i=1;i<=n;i++)
		for (I1=p[i].connected.begin();I1!=p[i].connected.end();I1++)
			for (I2=p[i].connected.begin();I2!=p[i].connected.end();I2++)
				if (*I1!=*I2)
				{
					cache=p[*I1].data*p[*I2].data;
					ans=max(ans,cache);
					sum+=cache%M;
				}
	cout<<ans<<' '<<sum%M<<endl;
	return 0;
}

