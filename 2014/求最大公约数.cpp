#include<iostream>
using namespace std;
int main()
{
    int a,b,A,B,m,n;
    bool OK(0);
    cin>>a>>b;
    for (m=1;OK==0&&m<=a&&m<=b;m++)
    {
        A=a%m;
        B=b%m;
        if (A==0&&B==0) n=m;
    }
    cout<<n<<endl;
    return 0;
}
