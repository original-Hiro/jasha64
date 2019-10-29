#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
ifstream cin("scholar.in");
ofstream cout("scholar.out");
struct student
{
    string name;
    int mark1,mark2,article,scholar,num;
    char manager,west;
} stu[105];
bool comp(const student &x,const student &y)
{
    return x.scholar>y.scholar;
}
int main()
{
    int i,n,sum(0),pos(0);
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>stu[i].name>>stu[i].mark1>>stu[i].mark2>>stu[i].manager>>stu[i].west>>stu[i].article;
        stu[i].scholar=0;
        stu[i].num=i;
    }
    for (i=0;i<n;i++)
    {
        if (stu[i].article>=1&&stu[i].mark1>80)
        {
            stu[i].scholar+=8000;
            sum+=8000;
        }
        if (stu[i].mark1>85&&stu[i].mark2>80) 
        {
            stu[i].scholar+=4000;
            sum+=4000;
        }
        if (stu[i].mark1>90)
        {
            stu[i].scholar+=2000;
            sum+=2000;
        }
        if (stu[i].west=='Y'&&stu[i].mark1>85)
        {
            stu[i].scholar+=1000;
            sum+=1000;
        }
        if (stu[i].manager=='Y'&&stu[i].mark2>80)
        {
            stu[i].scholar+=850;
            sum+=850;
        }
    }
    sort(stu,stu+n,comp);
    for (i=1;i<n;i++)
    {
        if (stu[i].scholar<stu[i-1].scholar) break;
        if (stu[i].num<stu[pos].num) pos=i;
    }
    cout<<stu[pos].name<<endl<<stu[pos].scholar<<endl<<sum<<endl;
    return 0;
}

