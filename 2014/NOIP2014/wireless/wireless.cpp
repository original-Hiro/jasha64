#include<fstream>
using namespace std;
ifstream cin("wireless.in");
ofstream cout("wireless.out");
struct roadblock
{
	int x,y,importance;
} r[25];
int main()
{
	int d,n,i,j,k,num(0),ans(0),current(0);
	cin>>d>>n;
	for (i=0;i<n;i++) cin>>r[i].x>>r[i].y>>r[i].importance;
	for (i=0;i<=128;i++)
		for (j=0;j<=128;j++)
		{
			for (k=0;k<n;k++) if (i-d<=r[k].x&&i+d>=r[k].x&&j-d<=r[k].y&&j+d>=r[k].y) current+=r[k].importance;
			if (current>ans)
			{
				ans=current;
				num=0;
			}
			if (current==ans) num++;
			current=0;
		}
	cout<<num<<' '<<ans<<endl;
	return 0;
}

