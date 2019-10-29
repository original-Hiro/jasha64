#include<fstream>
#include<string>
#include<cctype>
using namespace std;
string word,s;
int main()
{
    ifstream cin("stat.in");
    ofstream cout("stat.out");
    getline(cin,word);
    getline(cin,s);
    for (int i=0;i<word.size();i++) word[i]=tolower(word[i]);
    for (int i=0;i<s.size();i++) s[i]=tolower(s[i]);
    int ans(0),first(-1);
    s=' '+s+' ';
    word=' '+word+' ';
    int k=s.find(word);
    while (k>=0&&k<s.size())
    {
        if (first==-1) first=k;
        ans++;
        s.erase(0,k+word.size()-1);
        k=s.find(word);
    }
    if (ans>0)    
        cout<<ans<<" "<<first<<endl;
    else cout<<first<<endl;
    return 0;
}
