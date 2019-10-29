#include<fstream>
using namespace std;
char a[256];
int main()
{
    ifstream cin("data.out");
    ofstream cout("data.in");
    string s;    
    while (getline(cin,s))
    {
        for (int i=0;i<s.size();i++)
            s[i]=s[i]-10;
        cout<<s<<endl;
    }
    //s="¹ú";
//    for (int i=0;i<s.size();i++)
//        cout<<(int)s[i]<<endl; 
    return 0;
}
