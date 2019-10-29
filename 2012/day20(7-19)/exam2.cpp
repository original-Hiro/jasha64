#include<iostream>
#include<algorithm>
using namespace std;
int a[]={0,10,20,30,40,50,60,70,80,90};
int main()
{
    int n=sizeof(a)/sizeof(int);
    //cout<<*(a+2)<<endl;
    int *p;
    p=a+2;   
    for (int i=0;i<3;i++)
        cout<<p[i]<<endl;   

    system("pause");
    return 0;
}
    
