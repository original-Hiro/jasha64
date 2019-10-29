#include<fstream>
using namespace std;
ifstream cin("poly.in");
ofstream cout("poly.out");
int a[101];
void solve(int n)
{
    for (int i=n;i>=0;i--)
    {
        if (a[i]==0) continue;
        if (a[i]<0) { cout<<'-';  a[i]=-a[i]; }
        else if (i<n) cout<<'+';
        if (a[i]>1||i==0&&a[i]==1) cout<<a[i];
        if (i>0) {
            cout<<'x';
            if (i>1) cout<<'^'<<i;
        }
    }
    cout<<endl;
}
        
        
int main()
{
    int n;
    cin>>n;
    for (int i=n;i>=0;i--) cin>>a[i];
    solve(n);
    return 0;
}
