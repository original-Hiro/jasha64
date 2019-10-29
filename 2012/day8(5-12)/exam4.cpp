#include<iostream>
using namespace std;
int main()
{
    int i,j,k,sum=0;
    for (i=1;i<=200;i++)
        for (j=1;j<=500;j++)                                
                if (5*i+2*j<1000) sum++;    
    cout<<sum<<endl; 
    system("pause");
    return 0;
}
