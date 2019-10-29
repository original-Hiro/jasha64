#include<iostream>
using namespace std;
int a[1001]={0};
int main()
{
    int n,i,x,j;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>x;
        a[x]++;
    }
    n=0;
    for (i=0;i<=1000;i++)
        if (a[i]>0) n++;
    cout<<n<<endl;
    for (i=0;i<=1000;i++)
        for (j=0;j<a[i];j++)
            cout<<i<<" ";
    cout<<endl;
    system("pause");
    return 0;
}    
        
