#include<iostream>
#include<string>
using namespace std;
struct stu
{
    string name;
    float chi,mat,eng,tot;
};
stu s[100];

int main()
{
    int n,i,j;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].chi>>s[i].mat>>s[i].eng;
        s[i].tot=s[i].chi+s[i].mat+s[i].eng;
    }
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            if (s[j].tot>s[i].tot||
                (s[j].tot==s[i].tot&&s[j].chi>s[i].chi)||
                (s[j].tot==s[i].tot&&s[j].chi==s[i].chi&&s[j].mat>s[i].mat) )               
            {
                stu t=s[i];
                s[i]=s[j];
                s[j]=t;
            }        
    cout<<endl;
    for (i=0;i<n;i++)
    {
        cout<<s[i].name;
        printf(" %6.1f%6.1f%6.1f %6.1f\n",
            s[i].chi,s[i].mat,s[i].eng,s[i].tot);
    }
    system("pause");
    return 0;
}
        
