#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double n,i,sum;
    cin>>n;
    for (i=1.0,sum=0;i<=n;i++)
        sum+=1.0/i;
    printf("%.3lf\n",sum);
    system("pause");
    return 0;
}
