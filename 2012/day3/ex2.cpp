#include<iostream>
#include<cstdio>  //standard input output
using namespace std;
int main()
{
    float w,fee;
    cin>>w;
    if (w<=10) fee=2.5;
    else
        fee=2.5+(w-10)*1.5;
    printf("%.1f\n",fee);
    //system("pause");
    return 0;
}
