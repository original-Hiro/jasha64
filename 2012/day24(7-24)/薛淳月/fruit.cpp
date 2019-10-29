#include<fstream>
#include<algorithm>
using namespace std;
long long a[30005],b[30005];
ifstream cin("fruit.in");
ofstream cout("fruit.out");
int main()
{
    int n,i,j,m,k,c;
    long long x,ans(0);
    cin>>n;
    fill(b,b+n+2,10000000000ll);
    fill(a,a+n+2,10000000000ll);
    for(i=0;i<n;i++) cin>>a[i];    
    sort(a,a+n);
    for(i=m=j=0,k=1;k<n;k++)
    {
        x=a[i]+a[i+1];
        c=1;
        if(x>a[i]+b[j]) {c=2; x=a[i]+b[j];}
        if(x>b[j]+b[j+1]) {c=3; x=b[j]+b[j+1];}
        switch(c)
        {
            case 1:b[m++]=x; i+=2; break;
            case 2:b[m++]=x; j++; i++; break;
            case 3:b[m++]=x; j+=2; break;
         }
         ans+=b[m-1];
    }
    cout<<ans<<endl;
    return 0;
}
    
    
