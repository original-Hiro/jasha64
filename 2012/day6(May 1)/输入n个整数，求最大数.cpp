#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,x,max,i;
    cin>>n;
    for (i=1,max=-2147483640;i<=n;i++)
    {
        cin>>x;
        if (x>max) max=x;
    }
    cout<<max<<endl;
    system("pause");
    return 0;
}
