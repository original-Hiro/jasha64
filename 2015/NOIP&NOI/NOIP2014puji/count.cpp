#include<fstream>
#include<set>
#include<iterator>
using namespace std;
ifstream cin("count.in");
ofstream cout("count.out");
int main()
{
	int n,i,j,k,a[105]={0},ans(0);
	set<int> f;
	set<int>::iterator h;
	cin>>n;
	for (i=0;i<n;i++)
	{
		cin>>a[i];
		for (j=0;j<i;j++) f.insert(a[j]+a[i]);
	}
	for (i=0;i<n;i++)
		for (h=f.begin();h!=f.end();h++)
			if (*h==a[i]) ans++;
	cout<<ans<<endl;
	return 0;
}

