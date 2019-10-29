#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b;
    c=a;
    a=b;
    b=c;
    printf("%d %d\n",a,b);
    system("pause");
    return 0;
}
