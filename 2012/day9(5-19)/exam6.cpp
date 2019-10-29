#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,i,k;
    for (a=2;a<=1000000;a++)
    {
        b=1;
        for (i=2,k=(int)sqrt(a);i<=k;i++)
            if (a%i==0)
                b+=i+a/i;  //将a的因子加到b中 
        if (k*k==a) b-=k;
        c=1;
        for (i=2,k=(int)sqrt(b);i<=k;i++)
            if (b%i==0)
                c+=i+b/i;  //将b的因子加到c中 
        if (k*k==b) c-=k;
        if (c==a&&a<b) cout<<a<<" "<<b<<endl;
    }
    system("pause");
    return 0;
}
    
