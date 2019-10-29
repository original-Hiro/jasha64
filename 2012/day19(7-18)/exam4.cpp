#include<iostream>
using namespace std;
long long a[50];
int main()
{
    int n;
    cin>>n;
    if (n==1||n==2) cout<<n<<endl;
    else {
        a[1]=1;
        a[2]=2;
        for (int i=3;i<=n;i++)
            a[i]=a[i-1]+a[i-2];
        cout<<a[n]<<endl;
    }
    system("pause");
    return 0;
}
