//编程求下列序列的累加和，累加n项，正整数n从键盘输入。 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a,b,c,n;  //a为分子，b为分母，c用于暂时储存变量。 
    double sum;
    while (cin>>n)
    {
        sum=0; a=2; b=1;
        for (int i=1;i<=n;i++)
        {
            sum+=a/(double)b;
            c=a+b; b=a; a=c;
        }
        printf("%.6lf\n",sum);
    }
    system("pause");
    return 0;
}
