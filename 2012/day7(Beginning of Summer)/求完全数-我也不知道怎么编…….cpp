//如果一个数等于其所有的因数（除了它本身）之和，则将这个数称作“完全数”。求1000
//以内所有的完全数。 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,sum; //j为i的因数
    for (i=1;i<=1000;i++)
    {
        sum=0;
        for (j=1;j<=i/2;j++)
            if (i%j==0)
                sum+=j;
        if (i==sum) cout<<i<<endl;
    }
    system("pause");
    return 0;
}
