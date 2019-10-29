#include<fstream>
using namespace std;
ifstream cin("equation.in");
ofstream cout("equation.out");
int main()
{
	int i,a[105],x1,x2,n,m;
	bool x1s(0),x2s(0);
	cin>>n>>m;
	for (i=0;i<=n;i++) cin>>a[i];
	if (n==1)
	{
		for (i=1;i<=m;i++)
			if (a[1]*i+a[0]==0)
			{
				x1=i;
				cout<<"1"<<endl<<i<<endl;
				return 0;
			}
		cout<<"0"<<endl;
		return 0;
	}
	else if (n==2) 
	{
		for (i=1;i<=m;i++)
			if (a[2]*i*i+a[1]*i+a[0]==0)
				if (!x1s)
				{
					x1=i;
					x1s=true;
				}
				else if (!x2s)
				{
					x2=i;
					x2s=true;
					break;
				}
		if (!x1s)
		{
			cout<<"0"<<endl;
			return 0;
		}
		else if (!x2s)
		{
			cout<<"1"<<endl<<x1<<endl;
			return 0;
		}
		else
		{
			cout<<"2"<<endl<<x1<<endl<<x2<<endl;
			return 0;
		}
	}
	else cout<<"0"<<endl;
	return 0;
}

