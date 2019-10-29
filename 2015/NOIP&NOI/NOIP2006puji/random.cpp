#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,num(0),number[105],i,j,t(0);
    cin>>n;
    for (i=0;i<n;i++) cin>>number[i];
    sort(number,number+n);
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            if (i!=j&&number[i]==number[j]) number[j]=0;
    for (i=0;i<n;i++) if (number[i]!=0) num++;
    cout<<num<<endl;
    for (i=0;i<n;i++)
    {
         if (number[i]!=0&&t!=num-1)
         {
            cout<<number[i]<<' ';
            t++;
         }
         else if (number[i]!=0) cout<<number[i];
    }
    cout<<endl;
    return 0;
}

