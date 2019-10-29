#include<fstream>
#include<algorithm>
using namespace std;
int a[30001];
int main()
{
    ifstream cin("group.in");
    ofstream cout("group.out");
    int n,w,i,j,ans(0);
    cin>>w>>n;
    for (i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for (i=0,j=n-1;i<=j;)    
    {
        if (a[i]+a[j]<=w)
            i++,j--;
        else j--;
        ans++;
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
