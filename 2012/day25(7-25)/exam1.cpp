#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N(10001);
int a[N],b[N],c[N];
void init(int *x)
{
    string s;
    cin>>s;
    x[0]=s.size();
    for (int i=0;i<x[0];i++)
        x[x[0]-i]=s[i]-'0';
}
void add(int *a,int *b,int *c)
{
    c[0]=max(a[0],b[0]);
    for (int i=1;i<=c[0];i++)
    {
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    if (c[c[0]+1]>0) c[0]++;
}
void multiply(int *a,int x,int *c)
{
    for (int i=1;i<=a[0];i++)
    {
        c[i]+=a[i]*x;
        c[i+1]=c[i]/10;
        c[i]%=10;
    }
    c[0]=a[0];
    while (c[c[0]+1]>0)
    {
        ++c[0];
        c[c[0]+1]=c[c[0]]/10;
        c[c[0]]%=10;
    }
}
    
        
void output(int *x)
{
    for (int i=c[0];i>=1;i--)
        cout<<c[i];
    cout<<endl;
}       
int main()
{
    fill(a,a+N,0);
    fill(b,b+N,0);
    fill(c,c+N,0);
    init(a);
   // init(b);
   // add(a,b,c);
    int x; cin>>x;
    multiply(a,x,c);
    output(c);
    system("pause");
    return 0;
}
