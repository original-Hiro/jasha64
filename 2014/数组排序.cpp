#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[5005],m,n;
    cin>>n;
    for (m=0;m<n;m++) cin>>a[m];
    sort(a,a+n);
    reverse(a,a+n);
    for (m=0;m<n-1;m++) cout<<a[m]<<' ';
    cout<<a[n-1];
    cout<<endl;
    return 0;
}
