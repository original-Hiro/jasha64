#include<iostream>
using namespace std;
float power(float x,int n)
{
    float s=1;
    for (int i=0;i<n;i++) 
        s*=x;
    return s;
}
int main()
{
    int x,n;
    while (cin>>x>>n)
        cout<<power(x,n)<<endl;
    system("pause");
    return 0;
} 
