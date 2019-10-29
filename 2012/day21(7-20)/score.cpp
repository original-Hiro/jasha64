#include<fstream>
#include<algorithm>
using namespace std;
const int N(5001);
struct node
{
    int No,score;
};
node a[N];
ifstream cin("score.in");
ofstream cout("score.out");
bool comp(const struct node &x,const struct node &y)
{
    if (x.score!=y.score) return (x.score>y.score);
    return (x.No<y.No);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>a[i].No>>a[i].score;
    sort(a,a+n,comp);
    int k=(int)(1.5*m);
    for (m=k;k<n;k++)
        if (a[k].score!=a[m-1].score) break;
    cout<<a[k-1].score<<" "<<k<<endl;
    for (int i=0;i<k;i++) 
        cout<<a[i].No<<" "<<a[i].score<<endl;
    return 0;
}
     
