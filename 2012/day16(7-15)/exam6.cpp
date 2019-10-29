#include<iostream>
#include<cmath>
using namespace std;
double pai()
{
    double s(0.0);
    for (int i=1;1.0/(i*i)>=1e-10;i++)
        s+=1.0/(i*i);
    return sqrt(6*s);
}
int main()
{
    double pi;
    pi=pai();
    printf("%.7lf\n",pi);
    system("pause");
    return 0;
}
