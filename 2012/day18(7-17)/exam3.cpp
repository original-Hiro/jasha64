#include<iostream>
using namespace std;
void rec(int a,int b,int &zhouchang,int &mianji)
{
    zhouchang=(a+b)*2;
    mianji=a*b;
}
int main()
{
    int a,b,c,s;
    cin>>a>>b;
    rec(a,b,c,s);
    cout<<c<<" "<<s<<endl;
    system("pause");
    return 0;
}
