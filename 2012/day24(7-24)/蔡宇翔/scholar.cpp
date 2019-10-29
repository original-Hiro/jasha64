#include<fstream>
#include<string>
using namespace std;
ifstream cin("scholar.in");
ofstream cout("scholar.out");
struct stu{
    string name;char gb,xb;int e,c,lw,jxj;
};
stu s[101];
int i;
int main()
{
    int n,sum(0),t(0);
    string nm;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].e>>s[i].c>>s[i].gb>>s[i].xb>>s[i].lw;
        if(s[i].e>80&&s[i].lw>0)s[i].jxj+=8000;
        if(s[i].e>85&&s[i].c>80)s[i].jxj+=4000;
        if(s[i].e>90)s[i].jxj+=2000;
        if(s[i].e>85&&s[i].xb=='Y')s[i].jxj+=1000;
        if(s[i].c>80&&s[i].gb=='Y')s[i].jxj+=850;
        sum+=s[i].jxj;
        if(s[i].jxj>t){t=s[i].jxj;nm=s[i].name;}
    }
    cout<<nm<<endl<<t<<endl<<sum<<endl;
    return 0;
}
    
