#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,n,i;
    double sum;   
    while (cin>>n)
    {
        sum=0;
        a=2; b=1;
        for (i=1;i<=n;i++)
        {
            sum+=a/(double)b;
            a=a+b;
            b=a-b;            
        }
        printf("%.3lf\n",sum);
    }    
    return 0;
}
