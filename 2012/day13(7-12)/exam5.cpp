#include<iostream>
#include<string>
using namespace std;
string c[1000];
int main()
{
    string s;
    int n,sum(0);
    cin>>n;    
    for (int i=0;i<n;i++)
    {
        cin>>s;
        if (s[0]=='c'||s[0]=='C')        
            c[sum++]=s;            
    }
    cout<<sum<<endl;
    for (int i=0;i<sum;i++)
        cout<<c[i]<<endl;
    system("pause");
    return 0;
}
