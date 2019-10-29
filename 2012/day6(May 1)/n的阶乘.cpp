#include<iostream>
using namespace std;
int main()
{
    int n,i,s;
    cin>>n;
    s=1;
    i=1;
    while (i<=n)
    {
        s*=i;
        i++;
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}
