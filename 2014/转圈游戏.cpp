#include<iostream>
using namespace std;
int pow(int x,int n)
{
	int result;
	if (n==0) return 1;
	else while((n&1)==0)
		{
			n>>=1;
			x*=x;
		}
	result=x;
	n>>=1;
	while(n!=0)
	{
		x*=x;
		if((n&1)!=0)
		result*=x;
		n>>=1;
	}
	return result;
}
int process(int n,int m,int k,int x)
{
	int pos,i;
	long long r;
	for (i=1;i<n;i++)
		if (m*i%n==0) break;
	r=pow(10,k);
	r%=i;
	pos=(m*r+x)%n;
	return pos;
} 
int main()
{
	int n,m,k,x;
	cin>>n>>m>>k>>x;
	cout<<process(n,m,k,x)<<endl;
	return 0;
}

