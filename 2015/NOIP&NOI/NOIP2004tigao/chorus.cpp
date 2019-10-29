#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("chorus.in");
ofstream cout("chorus.out");
int main()
{
    int i,j,n,a[1005],f[1005],g[1005],ans;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=1;
        g[i]=1;
    }
    for (i=2;i<=n;i++)
        for (j=1;j<i;j++)
            if (a[i]>a[j]) f[i]=max(f[i],f[j]+1);
    for (i=n;i>=2;i--)
        for (j=i;j>1;j--)
            if (a[j]>a[i]) g[j]=max(g[j],g[i]+1);
    ans=f[1]+g[1];
    for (i=1;i<=n;i++) ans=max(ans,f[i]+g[i]);
    cout<<n-ans+1<<endl;
    return 0;
}

