#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    while (cin>>n)
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n-i;j++) cout<<" ";    //输出第1个三角形左边空格 
            for (j=1;j<=2*i-1;j++) cout<<"*";  //输出第1个三角形星号 
            for (j=1;j<=2*(n-i);j++) cout<<" ";//输出第2个三角形左边空格
            for (j=1;j<=2*i-1;j++) cout<<"*";  //输出第2个三角形星号
            for (j=1;j<=2*(n-i);j++) cout<<" ";//输出第3个三角形左边空格
            for (j=1;j<=2*i-1;j++) cout<<"*";  //输出第3个三角形星号
            cout<<endl;  //换行 
        }
    
    return 0;
}
