#include<iostream>
using namespace std;
int main()
{
    int n,m[100005],k,p;
    cin>>n;
    p=1;
    for (k=0;n!=0;k++)
    {
        p=n%10;
        m[k]=p;
        n/=10;
    }
    for (p=0;p<k;p++) cout<<m[p];
    cout<<endl;
    return 0;
}
