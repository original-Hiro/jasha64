#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct stu{
    string name;
    int chi,mat,eng,tot;
};
stu s[10000];
bool bigger(const stu &x,const stu &y)
{
    if (x.tot!=y.tot) return (x.tot>y.tot);
    if (x.chi!=y.chi) return (x.chi>y.chi);    
    return (x.mat>y.mat);
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].chi>>s[i].mat>>s[i].eng;
        s[i].tot=s[i].chi+s[i].mat+s[i].eng;
    }
    sort(s,s+n,bigger);
    cout<<endl;
    for (int i=0;i<n;i++) 
        cout<<s[i].name<<' '<<s[i].chi<<' '<<s[i].mat<<' '<<s[i].eng<<' '<<s[i].tot<<endl;
    system("pause");
    return 0;
}
