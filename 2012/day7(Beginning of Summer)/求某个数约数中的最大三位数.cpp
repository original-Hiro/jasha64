#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    for (i=999;i>=100;i--)
    {
        if (n%i==0)   
        break;
    }
    cout<<i<<endl;
    system("pause");
    return 0;
}
