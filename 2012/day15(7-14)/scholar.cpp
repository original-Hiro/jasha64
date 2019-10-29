#include<fstream>
#include<string>
using namespace std;
struct stu{ int No,chi,mat,eng,tot; };
stu s[301];
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
    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (s[j].tot>s[i].tot||
                s[j].tot==s[i].tot&&s[j].chi>s[i].chi||
                s[j].tot==s[i].tot&&s[j].chi==s[i].chi&&s[j].No<s[i].No)
            {
                stu t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
    for (int i=0;i<5;i++)
        cout<<s[i].No<<" "<<s[i].tot<<endl;
    return 0;
}
