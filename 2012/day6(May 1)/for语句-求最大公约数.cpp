#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    for (c=a%b;c!=0;)
    a=b,b=c,c=a%b;
    cout<<b<<endl;
    system("pause");
    return 0;
}
