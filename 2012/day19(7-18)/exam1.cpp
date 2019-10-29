#include<iostream>
using namespace std;
int f(int n)
{
    if (n==0) return 0;
    else return f(n-1)+n;
}
int main()
{
    int x;
    while (cin>>x)
        cout<<f(x)<<endl;
    return 0;
}
    
