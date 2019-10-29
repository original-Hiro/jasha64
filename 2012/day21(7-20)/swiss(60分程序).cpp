//本程序只能得60分 
#include<fstream>
#include<algorithm>
using namespace std;
struct stu
{
    int No,fen,shili;
};
const int N(100001);
stu a[2*N];
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
    for (int i=0;i<n;i++)
        if (a[2*i].shili>a[2*i+1].shili)
            a[2*i].fen++;
        else a[2*i+1].fen++;
    sort(a,a+2*n,comp);
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
    
