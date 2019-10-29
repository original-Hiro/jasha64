#include<fstream>
using namespace std;
ifstream cin("ratio.in");
ofstream cout("ratio.out");
typedef long double LD;
int main()
{
	int A,B,L,a,b,i,j;
	LD NUM,num,cha(1000000.0);
	cin>>A>>B>>L;
	NUM=(LD)A/(LD)B;
	for (i=1;i<=L;i++)
		for (j=1;j<=L;j++)
		{
			num=(LD)i/(LD)j;
			if (num>=NUM&&num-NUM<cha)
			{
				a=i;
				b=j;
				cha=num-NUM;
			}
		}
	cout<<a<<' '<<b<<endl;
	return 0;
}

