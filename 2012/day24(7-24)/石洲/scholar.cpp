#include<fstream>
#include<string>
using namespace std;
ifstream cin("scholar.in");
ofstream cout("scholar.out");
struct stu{
    string name;
    int qm,bj,lw;
    char gb,xb;
};
stu s[1000];
int a[20000];
int main()
{
    int n,i,q(0),sum(0);
    string p;
    cin>>n;
    for (i=0;i<n;i++)
    { 
        cin>>s[i].name>>s[i].qm>>s[i].bj>>s[i].gb>>s[i].xb>>s[i].lw;
        if (s[i].gb=='Y'&&s[i].bj>80) a[i]+=850;
        if (s[i].xb=='Y'&&s[i].qm>85) a[i]+=1000;
        if (s[i].qm>90) a[i]+=2000;
        if (s[i].qm>85&&s[i].bj>80) a[i]+=4000;
        if (s[i].qm>80&&s[i].lw>=1) a[i]+=8000;
        if (a[i]>q)
        {
            p=s[i].name;
            q=a[i];
        }
    }  
    for (i=0;i<n;i++) sum+=a[i];
    cout<<p<<endl;
    cout<<q<<endl;
    cout<<sum<<endl;
    return 0;
}
   
