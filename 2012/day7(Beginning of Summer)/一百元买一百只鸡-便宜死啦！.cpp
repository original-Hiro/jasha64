//百钱百鸡问题：公鸡5钱一只，母鸡3钱一只，小鸡一钱3只，现在买100只鸡花了100钱，
//问三种鸡各买了多少只？ 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cock,hen,chicken;
    printf("cock hen chicken\n");
    for (cock=0;cock<=20;cock++)
        for (hen=0;hen<=33;hen++)
        {
            chicken=100-cock-hen;
            if (chicken%3==0 && 5*cock+3*hen+chicken/3==100)
                printf ("%4d%4d%6d\n",cock,hen,chicken);
        }
    system("pause");
    return 0;
}
