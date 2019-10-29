#include<iostream>
using namespace std;
int main()
{
	int n,ans(1);
	cin>>n;
	while (n!=0)
	{
		ans*=n%10/2;
		n/=2;
	}
	cout<<ans<<endl;
	return 0;
}

