#include<fstream>
#include<string>
#include<cctype>
using namespace std;
ifstream cin("expand.in");
ofstream cout("expand.out");
int p1,p2,p3;
string s;
void expand(int p)
{
    int i;
    char n;
    string temp;
    for (n=s[p-1]+1;n<s[p+1];n++) 
    {
        for (i=0;i<p2;i++)
        switch (p1)
        {
            case 1: temp+=n; break;
            case 2: temp+=toupper(n); break;
            case 3: temp+='*';
        }
    }   
    if (p3==1) cout<<temp;
    else for (i=temp.size()-1;i>=0;i--) cout<<temp[i];
}
bool expandable(int x)
{
    if (s[x]!='-') return false;
    if (s[x-1]>=s[x+1]) return false;
    if (islower(s[x-1])&&islower(s[x+1])) return true;
    if (isdigit(s[x-1])&&isdigit(s[x+1])) return true;
    return false;
}
int main()
{
    cin>>p1>>p2>>p3;
    cin>>s;
    int len(s.size()),i;
    if (len<=2) cout<<s<<endl;
    else
    {
        cout<<s[0];
        for (i=1;i<s.size()-1;i++)
            if (expandable(i)) expand(i);
            else cout<<s[i];
        cout<<s[s.size()-1]<<endl;
    }
    return 0;
}

