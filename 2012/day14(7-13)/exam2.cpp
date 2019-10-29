#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while (cin>>s)
    {
        int len=s.size();
        bool ok;
        ok=true;
        for (int i=0;i<len/2;i++)
            if (s[i]!=s[len-1-i])
            {
                ok=false;
                break;
            }
        if (ok) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    system("pause");
    return 0;
}
    
    
        
