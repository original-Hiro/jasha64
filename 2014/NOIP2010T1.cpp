#include<iostream>
using namespace std;
int main()
{
	int i,j,m,n,ram[105]={0},article[1005],num(0),temp(0);
	bool inside;
	cin>>m>>n;
	for (i=0;i<n;i++) cin>>article[i];
	for (i=0;i<n;i++)
	{
		for (j=0;j<m;j++) if (article[i]==ram[j]) inside=1;
		if (inside==0)
		{
			num++;
			temp++;
			ram[temp%m]=article[i];
		}
		inside=0;
	}
	cout<<num<<endl;
	return 0;
}

