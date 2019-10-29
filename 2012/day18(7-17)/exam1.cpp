#include<iostream>
using namespace std;
void myswap(int &x,int &y)
{
    int z;
    z=x;
    x=y;
    y=z;
}
int main()
{
    int a,b;
    cin>>a>>b;
    myswap(a,b);
    cout<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}
