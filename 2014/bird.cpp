#include<iostream>
#include<algorithm>
using namespace std;
const int INF(1000000000),M(10005);
int f[M][1005],a[M],b[M],h[M],l[M];
int main()
{
	int n,m,k,i,i1,i2,pos,c1,c2,ans(INF);
	cin>>n>>m>>k;
	for (i=0;i<n;i++) cin>>a[i]>>b[i];
	for (i=0;i<k;i++)
	{
		cin>>pos>>c1>>c2;
		l[pos]=c1;
		h[pos]=c2;
	}
	if (h[0]==0) h[0]=INF;
	for (i=1;i<=n;i++)
	{
		for (i1=0;i1<=m;i1++) f[i][i1]=INF;
		if (h[i]==0) h[i]=INF;
	}
	for (i1=1;i1<=m;i1++)
		if (l[1]<i1&&h[1]>i1)
			{
				if (i1+b[0]<=m) f[1][i1]=min(f[1][i1],f[0][i1+b[0]]);
				for (i2=0;i2<i1;i2++)
				{
					c1=(i1-i2)/a[0];
					if (c1*a[0]==i1-i2&&i1!=i2)
					f[1][i1]=min(f[1][i1],f[0][i2]+c1);
					if (i1==m)
					{
						c2=0;
						if (i2!=m) while (c2*a[0]+i2<i1) c2++;
						else c2=1;
						f[i][i1]=min(f[i][i1],f[i-1][i2]+c2);
					}
				}
			}
	for (i=2;i<=n;i++)
		for (i1=1;i1<=m;i1++)
			if (l[i]<i1&&h[i]>i1)
			{
				if (i1+b[i-1]<=m) f[i][i1]=min(f[i][i1],f[i-1][i1+b[i-1]]);
				for (i2=1;(i1==m?i2<=m:i2<i1);i2++)
				{
					c1=(i1-i2)/a[i-1];
					if (c1*a[i-1]==i1-i2&&i1!=i2)
					f[i][i1]=min(f[i][i1],f[i-1][i2]+c1);
					if (i1==m)
					{
						c2=0;
						if (i2!=m) while (c2*a[i-1]+i2<i1) c2++;
						else c2=1;
						f[i][i1]=min(f[i][i1],f[i-1][i2]+c2);
					}
				}
			}
	for (i=1;i<=m;i++) ans=min(ans,f[n][i]); 
	if (ans!=INF) cout<<'1'<<endl<<ans<<endl;
	else
	{
		cout<<'0'<<endl;
		ans=0;
		c1=INF;
		for (i=0;i<=n;i++)
		{
			for (i1=1;i1<=m;i1++) c1=min(c1,f[i][i1]);
			if (c1==INF) break;
			if (c1!=INF&&h[i]!=INF) ans++;
			c1=INF;
		}
		cout<<ans<<endl;
	}
	return 0;
}

