#include<iostream>
#include<string>
using namespace std;

void clear0(string &s)
{
    while (s[0]==' ') s.erase(0,1);
    while (s[s.size()-1]==' ') s.erase(s.size()-1,1);
}
int main()
{
    string s;
    getline(cin,s);
    clear0(s);
    cout<<s;
    system("pause");
    return 0;
}
