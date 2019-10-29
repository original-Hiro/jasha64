#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
class largeint
{		
	public:
	largeint () {*this=0;}
	largeint (const long long& num) {*this=num;}
	largeint (const string& s) {*this=s;}
	largeint operator = (long long a)
	{
		fill(s,s+S,0);
		size=0;
		do {
			s[size++]=a%B;
			a/=B;
		} while (a>0);
		isNeg=0;
		return *this;
	}
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
	friend largeint operator - (largeint a) {a.isNeg=!a.isNeg; return a;}
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
	friend largeint operator - (largeint a,const largeint& b)
	{
		if (a<b) return -(b-a);
		int i;
		bool done;
		for (i=0;i<b.size;i++) a.s[i]-=b.s[i];
		do {
			done=1;
			for (i=0;i<a.size-1;i++)
				if (a.s[i]<0)
				{
					a.s[i]+=B;
					a.s[i+1]--;
					done=0;
				}
		} while (!done);
		for (i=a.size-1;i>0;i--) if (a.s[i]!=0) break;
		a.size=i+1;
		return a;
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
	friend largeint operator / (const largeint& a,const largeint& b)
	{
		largeint res;
		for (res=0;;res=res+1) if (a<(res+1)*b) break;
		return res;
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
	static const int S=505,B=10000,W=4;
	int size,s[S];
	bool isNeg;
} x,y;
int main()
{
	string s,s1,s2;
	char X;
	int i;
	while (cin>>s)
	{
		for (i=0;i<s.size();i++) if (!isdigit(s[i])) break;
		x=s.substr(0,i);
		y=s.substr(i+1);
		X=s[i];
		switch (X)
		{
			case '+': cout<<x+y<<endl; break;
			case '-': cout<<x-y<<endl; break;
			case '*': cout<<x*y<<endl; break;
			case '/': cout<<x/y<<endl; break;
		}
	}
	return 0;
}

