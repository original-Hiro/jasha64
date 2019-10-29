#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
class largeint
{		
	public:
	largeint () {*this="0";}
	largeint (const string& s) {*this=s;}
	largeint operator = (const string& num)
	{
		fill(s,s+S,0);
		istringstream ss;
		size=num.size()/W+1;
		for (int i=0;i<size-1;i++)
		{
			ss.str(num.substr(num.size()-(i+1)*W,W));
			ss>>s[i];
			ss.clear();
		}
		if (num.size()%W)
		{
			ss.str(num.substr(0,num.size()%W));
			ss>>s[size-1];
		}
		else size--;
		isNeg=0;
		return *this;
	}
	friend largeint operator * (const largeint& a,const largeint& b)
	{
		largeint res;
		int i;
		for (i=0;i<a.size;i++)
			for (int j=0;j<b.size;j++)
			{
				res.s[i+j]+=a.s[i]*b.s[j];
				if (res.s[i+j]>=B)
				{
					res.s[i+j+1]+=res.s[i+j]/B;
					res.s[i+j]%=B;
				}
			}
		for (i=a.size+b.size;;i--) if (res.s[i]!=0) break;
		res.size=i+1;
		return res;
	}
	friend istream& operator >> (istream& cin,largeint& a)
	{
		string s;
		cin>>s;
		a=s;
		return cin;
	}
	friend ostream& operator << (ostream& cout,const largeint& a)
	{
		if (a.isNeg) cout<<'-';
		cout<<a.s[a.size-1];
		for (int i=a.size-2;i>=0;i--)
		{
			for (int j=10;a.s[i]*j<B&&j<B;j*=10) cout<<'0';
			cout<<a.s[i];
		}
		return cout;
	}
	private:
	static const int S=755,B=10000,W=4;
	int size,s[S];
	bool isNeg;
} x,y;
int main()
{
	cin>>x>>y;
	cout<<x*y<<endl;
	return 0;
}

