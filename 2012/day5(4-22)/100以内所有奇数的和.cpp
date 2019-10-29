#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int i,n,sum;
    cin>>n;
    sum=0;
    i=1;
    while (i<=n)
    {
        sum+=i;
        i+=2;
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
