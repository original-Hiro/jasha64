#include<iostream>
using namespace std;
int main()
{
    int T,a[1005],k;
    char c[1005];
    cin>>T;
    for (k=0;k<T;k++)
    {
        cin>>a[k];
        c[k]=a[k];
    }
    for (k=0;k<T;k++)
    cout<<c[k];
    cout<<endl;
    return 0;
}
