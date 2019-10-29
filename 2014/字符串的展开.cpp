#include<iostream>
#include<string>
using namespace std;
string process(string s,int p1,int p2,int p3)
{
       int pos,i,j,k;
       string x;
       pos=s.find("-");
       while (pos<=s.size()) 
       {
             k=pos;
             if (s[pos]==s[pos+1]-1)
                s.erase(pos,1);
             if (s[pos]<s[pos+1]&&s[pos]!=s[pos+1]-1)
             {
                s.erase(pos,1);
                if (p1==1)
                {
                   for (i=0;i<s[pos+1]-s[pos];i++)
                       for (j=0;j<p2;j++)
                           {
                              if (p3==1)
                                 {
                                        x=s[pos]+i+1;
                                        s.insert(k,x);
                                        k+=1;
                                 }
                              if (p3==2)
                                 {
                                        x=s[pos+1]-i-1;
                                        s.insert(k,x);
                                        k+=1;
                                 }
                           }

                }
                if (p1==2)
                {
                   for (i=0;i<s[pos+1]-s[pos];i++)
                       for (j=0;j<p2;j++)
                           {
                              if (p3==1)
                                 {
                                        if (48<=s[pos]<=57)
                                           {
                                              x=s[pos]+i+1;
                                              s.insert(k,x);
                                           }
                                        else 
                                        {
                                             x=s[pos]+i-31;
                                             s.insert(k,x);
                                        }
                                        k+=1;
                                 }
                              if (p3==2)
                                 {
                                        if (48<=s[pos]<=57)
                                        {
                                           x=s[pos+1]-i-1;
                                           s.insert(k,x);
                                        }
                                        else
                                        {
                                            x=s[pos+1]-i-33;
                                            s.insert(k,x);
                                        }
                                        k+=1;
                                 }
                           }
                }
                if (p1==3)
                {
                   for (i=0;i<s[pos+1]-s[pos];i++)
                       for (j=0;j<p2;j++)
                       {
                           s.insert(k,"*");
                           k+=1;
                       }
                }
             }
             pos=s.find("-",pos+1);
       }
       return s;
}
int main()
{
    int p1,p2,p3;
    string s;
    cin>>p1>>p2>>p3>>s;
    cout<<process(s,p1,p2,p3)<<endl;
    system("pause");
    return 0;
}
