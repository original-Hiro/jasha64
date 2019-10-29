#include<iostream>
#include<algorithm>
using namespace std;
struct maidservant
{
	long long flag[505]={0},possible;
	int num;
	bool avaliable;
} ms[505],tzh[255],woman[255];
bool comp(const maidservant &x,const maidservant &y)
{
	return x.possible<y.possible;
}
int main()
{
	int i,j,n,number,numbe,numb(1);
	long long cache(0),tzhB(0),womanB(0);
	bool done(0);
	cin>>n;
	for (i=1;i<=n;i++)
		for (j=i;j<=n;j++)
			if (i!=j)
			{
				cin>>ms[i].flag[j];
				ms[i].possible+=ms[i].flag[j];
				ms[i].num=i;
				ms[i].avaliable=1;
			}
	sort(ms+1,ms+n+1,comp);
	while (done==0)
	{
		for (i=1;i<=n;i++)
			if (ms[i].avaliable==1)
			{
				tzh[numb]=ms[i];
				ms[i].avaliable=0;
				cache=ms[i].flag[1];
				number=i;
				break;
			}
		for (i=1;i<=n;i++)
			if (ms[number].flag[i]>cache)
			{
				numbe=i;
				cache=ms[number].flag[i];
			}
		woman[numb]=ms[numbe];
		numb++;
		ms[i].avaliable=0;
		for (i=1;i<=n;i++)
		{
			if (ms[i].avaliable==1)
			{
				done=0;
				break;
			}
			done=1;
		}
	}
	for (i=1;i<=numb;i++)
		for (j=1;j<=n;j++)
		{
			womanB=max(womanB,woman[i].flag[j]);
			tzhB=max(tzhB,tzh[i].flag[j]);
		}
	if (tzhB>womanB) cout<<"1"<<endl<<tzhB<<endl;
	else cout<<"0"<<endl;
	return 0;
}

