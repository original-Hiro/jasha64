#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,wrong,right;
    getline(cin,s);
    cin>>wrong>>right;
    while (true)
    {
        int k=s.find(wrong);
        if (k>=0&&k<s.size) 
            s.replace(k,wrong.size(),right);
        else break;
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}
