#include<iostream>
using namespace std;
int main()
{
    int a,b,c,t;
    cin>>a>>b>>c;
    if (a>b) { t=a; a=b; b=t; }
    if (b>c) { t=b; b=c; c=t; }
    if (a>b) { t=a; a=b; b=t; }
    if (a+1==b&&b+1==c)
        cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    system("pause");
    return 0;
}
