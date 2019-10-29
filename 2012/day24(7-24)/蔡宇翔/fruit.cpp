#include<fstream>
#include<algorithm>
using namespace std;
long long a[30008],b[30008];
int main()
{
    ifstream cin("fruit.in");
    ofstream cout("fruit.out");
    int c,n,m,i,j,k;
    cin>>n;
    long long x,ans(0);
    fill(a,a+30008,10000000000ll);
    fill(b,b+30008,10000000000ll);
    for(i=0;i<n;i++)cin>>a[i];
    for(i=j=m=0,k=0;k<n-1;k++)
    {
        x=a[i]+a[i+1];c=1;
        if(a[i]+b[j]<x){x=a[i]+b[j];c=2;}
        if(b[j]+b[j+1]<x){x=b[j]+b[j+1];c=3;}
        switch(c)
        {
            case 1: b[m]=x; m++;i+=2;break;
            case 2: b[m]=x; m++;i++;j++;break;
            case 3: b[m]=x; m++;j+=2;break;
        }
        ans+=b[m-1];
    }
    cout<<ans<<endl;
    return 0;
}
