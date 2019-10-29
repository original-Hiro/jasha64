#include<iostream>
using namespace std;
int num_2(int L,int R)
{
    int num(0),i,k;
    for (i=L;i<=R;i++)
    {
        k=i;
        while (k!=0)
        {
            if (k%10==2) num++;
            k/=10;
        }
    }
    return num;
}
int main()
{
    int L,R;
    cin>>L>>R;
    cout<<num_2(L,R)<<endl;
    return 0;
}

