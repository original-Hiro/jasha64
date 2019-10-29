#include<iostream>
#include<cstdio>
using namespace std;
const int N(30008);
int fri[N],d[N]={0};
int f(int x)
{
    while (fri[x]!=x) x=fri[x];
    return x;
}
int main()
{
    freopen("friend.in","r",stdin);
    freopen("friend.out","w",stdout);
    int n,m,x,y,k1,k2;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) fri[i]=i;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        k1=f(x);
        k2=f(y);
        if (k1!=k2) fri[k2]=fri[x]=fri[y]=k1;
    }
    for (int i=1;i<=n;i++)  d[f(i)]++;       
    int ans(0);
    for (int i=1;i<=n;i++)
         if (d[i]>ans) ans=d[i];
    printf("%d\n",ans);
    return 0;
}
