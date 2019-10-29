//本程序只能得60分 
#include<fstream>
#include<algorithm>
using namespace std;
struct stu
{
    int No,fen,shili;
};
const int N(100001);
stu a[2*N],win[N],lose[N];
bool comp(const stu &x,const stu &y)
{
    if (x.fen!=y.fen) return x.fen>y.fen;
    return x.No<y.No;
}
ifstream cin("swiss.in");
ofstream cout("swiss.out");
int n;
void solve()
{
    int i,j,k;
    for (i=j=k=0;i<n;i++,j++,k++)
        if (a[2*i].shili>a[2*i+1].shili)
            a[2*i].fen++,win[j]=a[2*i],lose[k]=a[2*i+1];
        else a[2*i+1].fen++,win[j]=a[2*i+1],lose[k]=a[2*i];;
    for (i=j=k=0;j<n&&k<n;)
        if (comp(win[j],lose[k])) a[i++]=win[j++];
        else a[i++]=lose[k++];
    while (j<n) a[i++]=win[j++];
    while (k<n) a[i++]=lose[k++];
}
int main()
{
    int r,q;
    cin>>n>>r>>q;
    for (int i=0;i<2*n;i++) a[i].No=i+1;
    for (int i=0;i<2*n;i++) cin>>a[i].fen;
    for (int i=0;i<2*n;i++) cin>>a[i].shili;
    sort(a,a+2*n,comp);
    for (int i=0;i<r;i++)
        solve();
    cout<<a[q-1].No<<endl;
    return 0;
}
    
