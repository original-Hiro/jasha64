#include<iostream>
#include<string>
using namespace std;
int main()
{
    int k,p,pos(-1),num(0);
    string s,s1;
    getline(cin,s1);
    getline(cin,s);
    if ((s[0]==s1[0]||s[0]==s1[0]+32||s[0]==s1[0]-32)&&s[s1.size()]==' ')
       for (p=1;p<s1.size();p++)
           {
               if (s[p]!=s1[p]&&s[p]!=s1[p]+32&&s[p]!=s1[p]-32) break;
               if (p==s1.size()-1)
               {
                  if (pos==-1) pos=0;
                  num++;
               }
           }
    for (k=p;k<s.size()-s1.size();k++)
        if ((s[k]==s1[0]||s[k]==s1[0]+32||s[k]==s1[0]-32)&&s[k-1]==' '&&s[k+s1.size()]==' ')
               {
                    for (p=1;p<s1.size();p++)
                    {
                        if (s[k+p]!=s1[p]&&s[k+p]!=s1[p]+32&&s[k+p]!=s1[p]-32) break;
                        if (p==s1.size()-1)
                        {
                           if (pos==-1) pos=k;
                           num++;
                        }
                    }
                    k+=p-1;
               }
    if ((s[s.size()-s1.size()]==s1[0]||s[s.size()-s1.size()]==s1[0]+32||s[s.size()-s1.size()]==s1[0]-32)&&s[s.size()-s1.size()-1]==' ')
       for (p=1;p<s1.size();p++)
           {
               if (s[s.size()-s1.size()+p]!=s1[p]&&s[s.size()-s1.size()+p]!=s1[s.size()-s1.size()+p]+32&&s[p]!=s1[p]-32) break;
               if (p==s1.size()-1)
               {
                  if (pos==-1) pos=s.size()-s1.size();
                  num++;
               }
           }
    if (pos==-1) cout<<pos<<endl;
    else cout<<num<<' '<<pos<<endl;
    return 0;
}
