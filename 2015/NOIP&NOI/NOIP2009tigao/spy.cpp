#include<fstream>
#include<string>
using namespace std;
ifstream cin("spy.in");
ofstream cout("spy.out"); 
int main()
{
    int i,j;
    string a,b,p;
    char f[91]={0};
    cin>>a>>b>>p;
    for (i=0;i<a.size();i++)
    {
        if (f[a[i]]==0) f[a[i]]=b[i];
        else if (f[a[i]]!=b[i])
        {
            cout<<"Failed"<<endl;
            return 0;
        }
 
    }
    for (i=65;i<=90;i++)
        if (f[i]==0)
        {
            cout<<"Failed"<<endl;
            return 0;
        }
    for (i=65;i<=90;i++)
        for (j=65;j<=90;j++)
            if (i!=j&&f[i]==f[j])
                {
                    cout<<"Failed"<<endl;
                    return 0;
                }
    for (i=0;i<p.size();i++) cout<<f[p[i]];
    cout<<endl;
    return 0;
}

