#include<iostream>
using namespace std;
void printstar(int n)
{
     int a,b;
     for (a=1;a<=n;a++)
     {
         for (b=0;b<n-a;b++) cout<<' ';
         for (b=0;b<a*2-1;b++) cout<<'*';
         cout<<endl;
     }
}
int main()
{
    int n;
    cin>>n;
    printstar(n);
    return 0;
}
