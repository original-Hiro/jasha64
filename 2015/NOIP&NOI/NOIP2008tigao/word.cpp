#include<fstream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
ifstream cin("word.in");
ofstream cout("word.out");
bool isprime(int n)
{
    if (n<=1) return false;
    int i;
    for (i=2;i<=sqrt(n);i++) if (n%i==0) return false;
    return true;
}
int main()
{
    int i,word[123]={0},maxnum(0),minnum(100),ans;
    string s;
    cin>>s;
    for (i=0;i<s.size();i++) word[s[i]]++;
    for (i=97;i<=122;i++)
        if (word[i]!=0)
        {
            maxnum=max(maxnum,word[i]);
            minnum=min(minnum,word[i]);
        }
    ans=maxnum-minnum;
    if (isprime(ans)) cout<<"Lucky Word"<<endl<<ans<<endl;
    else cout<<"No Answer"<<endl<<"0"<<endl;
    return 0;
}

