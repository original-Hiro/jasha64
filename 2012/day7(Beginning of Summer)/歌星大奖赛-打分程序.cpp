#include<iostream>
#include<cstdio>
const int N(10);
using namespace std;
int main()
{
    float x,sum,max,min,ave;
    int i;
    sum=0;max=-100;min=100;
    for(i=0;i<N;i++)
    {
        cin>>x;
        sum+=x;
        max=(x>max?x:max);
        min=(x<min?x:min);
    }
    sum-=max+min;
    ave=sum/(N-2);
    printf("%.2f\n",ave);
    system("pause");
    return 0;
}
