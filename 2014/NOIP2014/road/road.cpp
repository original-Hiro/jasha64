#include<fstream>
#define INFINITE 100000000
using namespace std;
ifstream cin("road.in");
ofstream cout("road.out");
int x[10005],y[10005],f[10005];
bool can[10005];
int main()
{
	int i,k,n,m,s,t;
	bool done(0);
	cin>>n>>m;
	for (i=1;i<=n;i++) f[i]=INFINITE;
	for (i=1;i<=m;i++) cin>>x[i]>>y[i];
	cin>>s>>t;
	f[s]=0;
	can[t]=1;
	while (!done)
	{
		done=1;
		for (i=1;i<=m;i++)
			if (can[y[i]]==1&&can[x[i]]==0)
			{
				can[x[i]]=1;
				done=0;
			}
	}
	done=0;
	while (!done)
	{
		done=1;
		for (i=1;i<=m;i++)
			if (can[y[i]]==0&&can[x[i]]==1&&i!=s)
			{
				can[x[i]]=0;
				done=0;
			}
	}
	done=0;
	while (!done)
	{
		done=1;
		for (i=1;i<=m;i++)
			if (can[x[i]]&&can[y[i]]&&f[y[i]]>f[x[i]]+1)
			{
				f[y[i]]=f[x[i]]+1;
				done=0;
			}
	}
	if (f[t]==INFINITE) cout<<"-1"<<endl;
	else cout<<f[t]<<endl;
	return 0;
}

