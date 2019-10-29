#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
int f[10000];
int main()
{
    int n,W,w,v;
    cin>>n>>W;
    for (int i=0;i<n;i++)
        {
             cin>>w>>v;
             for (int j=W;j>=w;j--)
             f[j]=max(f[j],v+f[j-w]);
        }
    cout<<f[W]<<endl;
    system("pause");
    return 0;
}
