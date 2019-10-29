//输入正整数n，输出相应图案。 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int N,i,j;
    cin>>N;
    for (i=1;i<=N;i++)
    {
        for (j=1;j<=N-i;j++) cout<<" ";
        for (j=1;j<=2*i-1;j++) cout<<"*";
        cout<<endl;
    }
    system("pause");
    return 0;
}
