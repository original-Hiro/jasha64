#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int i,n,sum;
    cin>>n;
    for (i=1,sum=0;i<=n;i++) 
        sum+=i*i;
    cout<<sum<<endl;
    system("pause");
    return 0;
}
