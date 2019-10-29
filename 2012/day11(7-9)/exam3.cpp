#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
