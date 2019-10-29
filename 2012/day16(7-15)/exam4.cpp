#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    int z=x%y;
    while (z)
    {
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}

int main()
{
    int a,b;
    while (cin>>a>>b)
        cout<<gcd(a,b)<<endl;
    return 0;
}
