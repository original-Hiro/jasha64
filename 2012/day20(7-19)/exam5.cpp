#include<iostream>
using namespace std;
const int N(100000);
int a[N],b[N],c[N];
int main()
{
    int n,i,j,k;
    cin>>n;
    for (i=0;i<n;i++) cin>>a[i];
    for (i=0;i<n;i++) cin>>b[i];
    for (i=j=k=0;i<n&&j<n; )
        if (a[i]<b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];
    while (i<n) c[k++]=a[i++];
    while (j<n) c[k++]=b[j++];
    for (i=0;i<2*n;i++)
        cout<<c[i]<<" ";
    system("pause");
    return 0;
}
