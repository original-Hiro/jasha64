#include<iostream>
using namespace std;
int a[1000];
int main()
{
    int n,t,i,j;
    cin>>n;
    for (i=0;i<n;i++) cin>>a[i];
    
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (a[j]<a[i])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
            
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    system("pause");
    return 0;
}
    
