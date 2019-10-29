#include<iostream>
using namespace std;
int f(int x,int y)
{
    if (y==0) return 1;
    else return f(x,y-1)*x;
}
int main()
{
    int x,y;
    while(cin>>x>>y)
        cout<<f(x,y)<<endl;
    return 0;
}
