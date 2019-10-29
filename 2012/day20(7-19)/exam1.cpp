#include<iostream>
using namespace std;
int main()
{
    int a(5);
    int *p;    
    p=&a;
    cout<<*p<<endl;
    a++;
    cout<<*p<<endl;
    *p=10;
    cout<<a<<endl;
    system("pause");
    return 0;
}
    
    
