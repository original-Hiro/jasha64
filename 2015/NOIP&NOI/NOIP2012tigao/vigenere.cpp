#include<fstream>
#include<string>
using namespace std;
ifstream cin("vigenere.in");
ofstream cout("vigenere.out");
char vigenere(char k,char s)
{
    int a,b,n;
    a=k-97;
    if (65<=s&&s<=90) b=s-65;
    else b=s-97;
    n=b-a;
    if (n<0) n+=26;
    if (65<=s&&s<=90) return n+65;
    else return n+97;
}
void uncode(string k,string s)
{
    char key[1005]={0};
    int i;
    for (i=0;i<k.size();i++) if (65<=k[i]&&k[i]<=90) k[i]+=32;
    for (i=0;i<s.size();i++) key[i]=vigenere(k[i%k.size()],s[i]);
    cout<<key<<endl;
}
int main()
{
    string k,s;
    cin>>k>>s;
    uncode(k,s);
    return 0;
}

