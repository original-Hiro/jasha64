#include<iostream>
using namespace std;
int main()
{
    int x;
    float y(3.5),z(2.7);
    x=y*((z+2.3)-2*5);
    cout<<x<<endl;
    int a(1),b(5),c(8);
    a+=b;
    b*=c;
    cout<<a<<" "<<b<<" "<<c<<endl;
    a=1;
    b=++a;
    cout<<a<<" "<<b<<endl;
    system("pause");
    return 0;
}
