#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,i,k;
    while (cin>>n)
    {
        cout<<n<<"=1";
        for (i=2,k=(int)sqrt(n);i<=k;i++)
            while (n%i==0)
            {
                cout<<"*"<<i;
                n/=i;
            }
        if (n>1) cout<<"*"<<n;
        cout<<endl;                
    }
    return 0;
}
