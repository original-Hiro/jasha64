#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    c=a%b;
    while (c!=0)
    {
        a=b; b=c; c=a%b;
    }
    cout<<b<<endl;
    system("pause");
    return 0;
}
