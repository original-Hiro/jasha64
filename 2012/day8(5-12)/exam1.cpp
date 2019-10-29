#include<iostream>
using namespace std;
int main()
{
    int n=0,i,j;
    for (i=2;i<=100;i++)
    {
        for (j=2;j<=i/2;j++)
            if (i%j==0) 
                break;
        if (j>i/2) 
        {
            cout<<i<<" ";
            n++;
            if (n%5==0) cout<<endl;   
        }
    }
    system("pause");
    return 0;
}
