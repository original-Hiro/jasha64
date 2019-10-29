#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n1(0),n2(0),n3(0),n[55],k;
    string s;
    cin>>s;
    for (k=0;k<s.size();k++)
    {
        if (s[k]>=65&&s[k]<=90) n1++;
        if (s[k]>=97&&s[k]<=122) n2++;
        if (s[k]>=48&&s[k]<=57) n3++;
    }
    cout<<n1<<' '<<n2<<' '<<n3<<endl;
    return 0;
}
