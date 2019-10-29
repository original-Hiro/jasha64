#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int n,i,j;
    while (cin>>s>>n)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<s.size()-1;j++)
                if (s[j]>s[j+1])
                    break;
            s.erase(j,1);
        }
        cout<<s<<endl;
    }
    system("pause");
    return 0;
}     
