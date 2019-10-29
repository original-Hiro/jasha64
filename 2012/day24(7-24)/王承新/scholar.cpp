#include<fstream>
#include<string>
using namespace std;
ifstream cin("scholar.in");
ofstream cout("scholar.out");
struct stu
{
    string name;
    int ssco;
    int csco;
    char cap;
    char west;
    int art;
    int get;
};
stu s[100];
int get_z(0);
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].name>>s[i].ssco>>s[i].csco>>s[i].cap>>s[i].west>>s[i].art;
    }
    for(int i=0;i<n;i++)
    {
        if(s[i].ssco>80&&s[i].art>0) s[i].get+=8000;
        if(s[i].ssco>85&&s[i].csco>80) s[i].get+=4000;
        if(s[i].ssco>90) s[i].get+=2000;
        if(s[i].ssco>85&&s[i].west=='Y') s[i].get+=1000;
        if(s[i].csco>80&&s[i].cap=='Y') s[i].get+=850;
    }
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(s[j].get>s[i].get)
            {
                stu t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
    for(int i=0;i<n;i++)
        get_z+=s[i].get;
    cout<<s[0].name<<endl;
    cout<<s[0].get<<endl;
    cout<<get_z<<endl;
    return 0;
}
   
