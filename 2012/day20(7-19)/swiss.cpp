#include<fstream>
#include<algorithm>
using namespace std;
const long N(100001);
struct node
{
    long No,shili,score;
};
node a[N+N+1],win[N],lose[N];
long n,r,q;
bool comp(const node &x,const node &y)
{
    if (x.score!=y.score) return (x.score>y.score);
    return (x.No<y.No);
}
void deal()
{
    long i,j,k,j1,k1;
    for (i=0;i<n;i++)
        if (a[2*i].shili>a[2*i+1].shili)
            a[2*i].score++,win[i]=a[2*i],lose[i]=a[2*i+1];
        else a[2*i+1].score++,win[i]=a[2*i+1],lose[i]=a[2*i];
    for (i=j=k=0;j<n&&k<n;i++)
        a[i]=(comp(win[j],lose[k])?win[j++]:lose[k++]);
    while (j<n) a[i++]=win[j++];
    while (k<n) a[i++]=lose[k++];
}          
int main()
{
    ifstream cin("swiss.in");
    ofstream cout("swiss.out");    
    cin>>n>>r>>q;
    for (long i=0;i<n+n;i++) { cin>>a[i].score;   a[i].No=i+1; }
    for (long i=0;i<n+n;i++) cin>>a[i].shili;
    sort(a,a+2*n,comp);
    for (long i=0;i<r;i++) deal();
    cout<<a[q-1].No<<endl;
    return 0;
}
