#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("hanoi.in");
ofstream cout("hanoi.out");
int a[100]={0};
void multiply(int *a,int x)
{
    int jw=0;
    for (int i=1;i<=a[0];i++)
    {
        a[i]=a[i]*x+jw;
        jw=a[i]/10;
        a[i]%=10;
    }    
    while (jw>0)
    {
        ++a[0];
        a[a[0]]=jw%10;
        jw/=10;        
    }
}
void solve(int n)
{
    a[0]=1;    a[1]=1;       
    for (int i=2;i<=n;i++)
    {
        multiply(a,2);
        a[1]++;
    }
    multiply(a,2);
}
void output(int *a)
{
    for (int i=a[0];i>=1;i--) 
        cout<<a[i];
    cout<<endl;
}
    
int main()
{
    int n;
    cin>>n;
    solve(n);    
    output(a);
    return 0;
}
    
    
    
