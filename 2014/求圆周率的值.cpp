#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double pi(0),n;
    for (n=1;n<=1000000;n++)
        pi+=1/(n*n);
    pi*=6;
    pi=sqrt(pi); 
    printf("%.3lf",pi);
    return 0;
}
