#include<fstream>
#include<string>
using namespace std;
char a[128]={0},b[128]={0};
ifstream cin("spy.in");
ofstream cout("spy.out");
bool solve(string s1,string s2,string s3)
{
     for (int i=0;i<s1.size();i++)
         if (b[s1[i]]==0)
            b[s1[i]]=s2[i];
         else if (b[s1[i]]!=s2[i]) return false;
     for (int i=0;i<s2.size();i++)
         if (a[s2[i]]==0)
            a[s2[i]]=s1[i];
         else if (a[s2[i]]!=s1[i]) return false;
     for (char ch='A';ch<='Z';ch++)
     {
        if (a[ch]==0) return false;
        if (b[ch]==0) return false;
     }
     for (int i=0;i<s3.size();i++)
        s3[i]=b[s3[i]];
     cout<<s3<<endl;
     return true;
}
int main()
{    
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    if (!solve(s1,s2,s3))
        cout<<"Failed"<<endl;
    return 0;
}
    
