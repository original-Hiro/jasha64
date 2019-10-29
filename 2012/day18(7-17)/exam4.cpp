#include<iostream>
using namespace std;
void zhuanhuan(string &s)
{
    for (int i=0;i<s.size();i++)
        if (s[i]>='A'&&s[i]<='Z')
            s[i]=s[i]-'A'+'a';
}
int main()
{
    string s;
    getline(cin,s);
    zhuanhuan(s);
    cout<<s<<endl;
    system("pause");
    return 0;
}
