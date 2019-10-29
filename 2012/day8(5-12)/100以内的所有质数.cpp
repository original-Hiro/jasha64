//编程求100以内的所有质数，每行输出5个，空格隔开。 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int output(0),i,j; //i为被除数，j为除数。 
    for (i=2;i<=100;i++)
    {
        for (j=2;j<=i/2;j++)
            if (i%j==0)
                break;
        if (j>i/2)
        {
            cout<<i<<" ";
            output++;
            if (output%5==0) cout<<endl;
        }
    }
    system("pause");
    return 0;
}
