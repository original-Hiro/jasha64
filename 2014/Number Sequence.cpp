#include<iostream>
#include<cstdio>
using namespace std;
int f(int A,int B,int n)
{
    if (n==1||n==2) return 1;
    else return (A*f(A,B,n-1)+B*f(A,B,n-2))%7;
}
int main()
{
    int A,B,n,k1(0),k2,m[100005]={0};
    while (cin>>A>>B>>n)
    {
          k1++;
          if (A==0) 
          {
             m[k1]=0;
             break;
          }
          else m[k1]=f(A,B,n); 
    }
    for (k2=1;k2<k1;k2++)
        cout<<m[k2]<<endl;
    return 0;
}
