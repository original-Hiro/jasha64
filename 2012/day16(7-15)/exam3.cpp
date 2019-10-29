#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int x)
{
    for (int j=2;j<=(int)sqrt(x);j++)
        if (x%j==0) return false;
    return true;
}
    
int main()
{
    int i;
    for (i=2;i<=1000;i++)
        if (isprime(i)) cout<<i<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
