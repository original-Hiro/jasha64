#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
struct stu{ int No,chi,mat,eng,tot; };
stu s[301];
bool comp(const stu &x,const stu &y)
{
    if (x.tot!=y.tot) return x.tot>y.tot;
    if (x.chi!=y.chi) return x.chi>y.chi;
    return x.No<y.No;
}
int main()
{
    ifstream cin("scholar.in");
    ofstream cout("scholar.out");
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        s[i].No=i+1;
        cin>>s[i].chi>>s[i].mat>>s[i].eng;
        s[i].tot=s[i].chi+s[i].mat+s[i].eng;
    }
    sort(s,s+n,comp);
    for (int i=0;i<5;i++)
        cout<<s[i].No<<" "<<s[i].tot<<endl;
    return 0;
}
