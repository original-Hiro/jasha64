//如果一个正整数的各位数字的立方和等于它本身，则该数为阿姆斯特朗数。求1000以内的
//所有阿姆斯特朗数。 
#include<iostream>
using namespace std;
int main()
{
    int x,i,sum;
    for (i=1;i<1000;i++)
    {
        sum=0;
        x=i;
        while (x>0)
        {
            sum+=(x%10)*(x%10)*(x%10);
            x/=10;
        }
        if (sum==i) cout<<i<<endl;
    }
    system("pause");
    return 0;
}
