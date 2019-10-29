#include<iostream>
using namespace std;
int main()
{
    int a(5);
    int &b(a),&c(a);
    cout<<b<<endl;
    a++;
    cout<<b<<endl;
    c++;
    cout<<a<<endl;
    system("pause");
    return 0;
}
    
