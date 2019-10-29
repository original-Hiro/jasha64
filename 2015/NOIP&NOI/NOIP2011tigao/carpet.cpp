#include<fstream>
#include<cstdio>
using namespace std;
ifstream cin("carpet.in");
ofstream cout("carpet.out");
struct carpet
{
    int x1,x2,y1,y2;
} carpet[10005];
void process(int n,int a,int b)
{
    int i;
    for (i=n;i>=1;i--)
        if (carpet[i].x1<=a&&carpet[i].x2>=a&&carpet[i].y1<=b&&carpet[i].y2>=b)
        {
            cout<<i<<endl;
            return;
        }
    cout<<"-1"<<endl;
}
int main()
{
    int n,a,b,g,k,i,x,y;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a>>b>>g>>k;
        carpet[i].x1=a;
        carpet[i].x2=a+g;
        carpet[i].y1=b;
        carpet[i].y2=b+k;
    }
    cin>>a>>b;
    process(n,a,b);
    return 0;
}

