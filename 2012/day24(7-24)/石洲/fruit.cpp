#include<fstream>
using namespace std;
const int N(30005);
long long a[N],b[N];
int main()
{
    ifstream cin("fruit.in");
    ofstream cout("fruit.out");
    int n,i,j,k,m,c;
    long long x,ans(0);
    cin>>n;
    fill(a,a+N,10000000000ll);
    fill(b,b+N,10000000000ll);
    for (i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for (i=j=m=0,k=1;k<n;k++)
    {
        x=a[i]+a[i+1];
        c=1;
        if (a[i]+b[j]<x)
        {
            x=a[i]+b[j];
            c=2;
        }
        if (b[j]+b[j+1]<x)
        {
            x=b[j]+b[j+1];
            c=3;
        }
        switch (c)
        {
            case 1:b[m++]=x; i+=2; break;
            case 2:b[m++]=x; i++; j++; break;
            case 3:b[m++]=x; j+=2; break;
        }
        ans+=x;
    }
    cout<<ans<<endl;
    return 0;
}
        
