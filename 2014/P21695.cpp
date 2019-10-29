#include<iostream>
using namespace std;
int main()
{
    double x,n,i,s(0);
    cin>>x;
    for (n=1;true;n++)
    {
        for (i=1;i<=n;i++) s+=1/i;
        if (s>x) break;
        else s=0;
    }
    cout<<n<<endl;
    return 0;
}
