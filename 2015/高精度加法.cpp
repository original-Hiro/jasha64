#include<iostream>
#include<vector>
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
	friend largeint operator + (largeint a,const largeint& b)
	{
		if (a.size<b.size) return b+a;
		int i;
		bool done;
		for (i=0;i<b.size;i++) a.s[i]+=b.s[i];
		do {
			done=1;
			for (i=0;i<a.size-1;i++)
				if (a.s[i]>=B)
				{
					a.s[i+1]+=a.s[i]/B;
					a.s[i]%=B;
					done=0;
				}
			if (a.s[a.size-1]>=B)
			{
				a.s[a.size++]+=a.s[i]/B;
				a.s[a.size]%=B;
			}
		} while (!done);
		return a;
	}
	friend bool operator < (const largeint& a,const largeint& b)
	{
		if (a.size!=b.size) return a.size<b.size;
		for (int i=a.size-1;i>=0;i--) if (a.s[i]!=b.s[i]) return a.s[i]<b.s[i];
		return false;
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
	static const int S=1255,B=100000000,W=8;
	int size,s[S];
	bool isNeg;
} x,y;
int main()
{
	cin>>x>>y;
	cout<<x+y<<endl;
	return 0;
}

