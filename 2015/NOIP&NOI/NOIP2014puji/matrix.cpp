#include<fstream>
using namespace std;
ifstream cin("matrix.in");
ofstream cout("matrix.out");
int main()
{
	int n,line,row,x(1),y(1),status(0);
	long long ans(1);
	bool tbc(0);
	cin>>n>>row>>line;
	while (x!=line||y!=row)
	{
		if ((x!=line&&y!=row)||!tbc)
			switch (status)
			{
				case 0: x+=n-1;	ans+=n-1; status=1; tbc=1; break;
				case 1: y+=n-1; ans+=n-1; status=2; tbc=1; break;
				case 2: x-=n-1; ans+=n-1; status=3; tbc=1; break;
				case 3: y-=n-2; ans+=n-2; status=4; tbc=1; break;
				case 4: x++; ans++; status=0; n-=2; tbc=1; break;
			}
		if (x==line&&tbc)
			switch (status)
			{
				case 1: y++; ans++; break;
				case 3: y--; ans++; break;
				default: tbc=0; break;
			}
		else if (y==row&&tbc)
			switch (status)
			{
				case 2: x--; ans++; break;
				case 0:
				case 4: x++; ans++; break;
				default: tbc=0; break;
			}
	}
	cout<<ans<<endl;
	return 0;
}

