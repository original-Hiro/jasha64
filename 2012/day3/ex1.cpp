#include<iostream>
using namespace std;
int main()
{
    int n;
    float qian;
    cin>>n;
    if (n>=10) qian=n*2.5*0.8;
    else qian=2.5*n;
    printf("%.2f\n",qian);
    system("pause");
    return 0;
}
    
