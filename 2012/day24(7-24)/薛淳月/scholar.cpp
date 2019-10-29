#include<fstream>
#include<string>
using namespace std;
struct stu
{
    string name;
    int qimo,banji;
    char ganbu,xibu;
    int lunwen,money;
};
stu s[102];
ifstream cin("scholar.in");
ofstream cout("scholar.out");
int main()
{
    int n,i,sum(0),maxmoney;
    string maxname;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i].name>>s[i].qimo>>s[i].banji>>s[i].ganbu>>s[i].xibu>>s[i].lunwen;
    for(i=0;i<n;i++)
    {    
        s[i].money=0;
        if(s[i].qimo>80&&s[i].lunwen>=1) s[i].money+=8000;
        if(s[i].qimo>85&&s[i].banji>80) s[i].money+=4000;
        if(s[i].qimo>90) s[i].money+=2000;
        if(s[i].qimo>85&&s[i].xibu=='Y') s[i].money+=1000;
        if(s[i].banji>80&&s[i].ganbu=='Y') s[i].money+=850;
        sum+=s[i].money; 
    }
    maxmoney=s[0].money;
    maxname=s[0].name;
    for(i=1;i<n;i++)
        if(maxmoney<s[i].money)
        {   maxmoney=s[i].money;
            maxname=s[i].name;
        }           
    cout<<maxname<<endl<<maxmoney<<endl<<sum<<endl;
    return 0;
}   
        
    
