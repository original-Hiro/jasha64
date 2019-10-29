#include<iostream>
#include<string>
using namespace std;
int main()
{
    //cout<<'\a'<<endl;
    string s("abcdefgh"),s1;
    s1=s.substr(2,3);
    cout<<s1<<endl;
    system("pause");
    return 0;
}
