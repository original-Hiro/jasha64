#include<iostream>
using namespace std;
int main()
{
    int a,b;
    bool TRUE;
    cin>>a;
    b=a;
    b%=4;
    if (b==0)
    {
       TRUE=1;
       b=a;
       b%=100;
       if (b==0) TRUE=0;
       b=a;
       b%=400;
       if (b==0) TRUE=1;       
    }
    else TRUE=0;
    if (TRUE==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
