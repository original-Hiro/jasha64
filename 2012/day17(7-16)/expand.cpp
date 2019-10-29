#include<fstream>
#include<string>
using namespace std;
int p1,p2,p3;
string s;
ifstream cin("expand.in");
ofstream cout("expand.out");
bool CanExpand(int i)
{
    if (s[i]!='-') return false;
    if (s[i-1]>=s[i+1]) return false;
    if (s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9') return true;
    if (s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z') return true;
    return false;    
}
void expand(int i)
{
     string temp;
     for (char c=s[i-1]+1;c<s[i+1];c++)
        for (int j=0;j<p2;j++)
            switch (p1)
            {
                case 1: temp+=c; break;
                case 2: if (c>='a'&&c<='z') temp+=(char)(c-32);
                        else temp+=c;
                        break;
                case 3: temp+='*'; break;
            }
     if (p3==1) cout<<temp;
     else for (int i=temp.size()-1;i>=0;i--) cout<<temp[i];
}
int main()
{
    cin>>p1>>p2>>p3>>s;
    cout<<s[0];
    for (int i=1;i<s.size()-1;i++)
        if (CanExpand(i))
            expand(i);
        else cout<<s[i];
    cout<<s[s.size()-1]<<endl;
    return 0;
}
    
