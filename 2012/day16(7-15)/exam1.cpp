#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
float area(float a,float b,float c)
{
    float d,yy;
    d=(a+b+c)/2; 
    yy=sqrt(d*(d-a)*(d-b)*(d-c));
    return yy;
}
int main()
{
    float x,y,z,s;
    cin>>x>>y>>z;
    s=area(x,y,z);
    printf("%.2f\n",s);
    system("pause");
    return 0;
}
    
