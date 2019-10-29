#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("link.in");
ofstream cout("link.out");
struct point
{
	int data,linknum,connected[20005];
} p[20005];
int main()
{
	int i,j,k,n,a,b;
	long long int ans(0),sum(0);
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>a>>b;
		p[a].connected[p[a].linknum]=b;
		p[b].connected[p[b].linknum]=a;
		p[a].linknum++;
		p[b].linknum++;
	}
	for (i=1;i<=n;i++) cin>>p[i].data;
	for (i=1;i<=n;i++)
		for (j=0;j<p[i].linknum;j++)
			for (k=0;k<p[p[i].connected[j]].linknum;k++)
				if (p[p[i].connected[j]].connected[k]!=i)
				{
					ans=max(ans,(long long int)p[i].data*p[p[p[i].connected[j]].connected[k]].data);
					sum+=p[i].data%10007*p[p[p[i].connected[j]].connected[k]].data%10007;
					sum%=10007;
				}
	cout<<ans<<' '<<sum<<endl;
	return 0;
}

