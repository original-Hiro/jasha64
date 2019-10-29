#include<iostream>
using namespace std;
int main()
{
    int x;  //声明x为整型 
    float y(3.5);
    x=5;
    cout<<x+y<<endl;
    cout<<x<<endl;
    x=100;
    cout<<x<<endl;
    x=20;
    cout<<x<<endl;
    x=22; y=5;
    cout<<x/(int)y<<endl;   
    int a(2),b(5),c(8);
    cout<<((++a),(b--),(c+b))<<endl;
    cout<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}
