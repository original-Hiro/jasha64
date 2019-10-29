#include<fstream>
#include<algorithm>
using namespace std;
const int N(1005);
struct node
{
    int num,No; //num表示分隔数目 
};
node ht[N],lt[N];
ifstream cin("seat.in");
ofstream cout("seat.out");
bool comp1(const node &x,const node &y)
{
    return x.num>y.num;
}
bool comp2(const node &x,const node &y)
{
    return x.No<y.No;
}
int main()
{
    int m,n,k,L,d,x1,y1,x2,y2;
    cin>>m>>n>>k>>L>>d;
    for (int i=0;i<m;i++) { ht[i].No=i+1; ht[i].num=0;}
    for (int i=0;i<n;i++) { lt[i].No=i+1; lt[i].num=0;}    
    for (int i=0;i<d;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        if (x1==x2) lt[min(y1,y2)-1].num++;
        if (y1==y2) ht[min(x1,x2)-1].num++;
    }
    sort(ht,ht+m,comp1); 
    sort(ht,ht+k,comp2);
    cout<<ht[0].No;  for (int i=1;i<k;i++) cout<<" "<<ht[i].No; cout<<endl;
    sort(lt,lt+n,comp1);
    sort(lt,lt+L,comp2);
    cout<<lt[0].No;  for (int i=1;i<L;i++) cout<<" "<<lt[i].No; cout<<endl;
    return 0;
}
