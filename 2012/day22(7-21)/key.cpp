#include<fstream>
using namespace std;
char a[256];
int main()
{
    ifstream cin("data.in");
    ofstream cout("data.out");    
    string s;
    while (getline(cin,s))
    {
        for (int i=0;i<s.size();i++)
            s[i]=s[i]+10;
        cout<<s<<endl;
    }
    return 0;
}
    
