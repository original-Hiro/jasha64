#include<iostream>
using namespace std;
class Complex
{
	public:
	Complex () {real=0;imag=0;}
	Complex (int a,int b) {real=a;imag=b;}
	void display() {cout<<'('<<real<<','<<imag<<')'<<endl;}
	Complex operator += (const Complex &a)
	{
		return Complex (real+=a.real,imag+=a.imag);
	}
	friend Complex operator + (Complex &a,Complex &b)
	{
		return Complex (a.real+b.real,a.imag+b.imag);
	}
	friend istream& operator >> (istream &input,Complex &a)
	{
		input>>a.real>>a.imag;
		return input;
	}
	friend ostream& operator << (ostream &output,Complex &a)
	{
		output<<'('<<a.real<<','<<a.imag<<')';
		return output;
	}
	friend bool operator < (const Complex &a,const Complex &b)
	{
		return (a.real<b.real&&a.imag<b.imag);
	}
	friend bool operator > (const Complex &a,const Complex &b)
	{
		return (a.real>b.real&&a.imag>b.imag);
	}
	private: int real,imag;
}a(3,4),b;
int main()
{
	a.display();
	cout<<a<<endl;
	cout<<b<<endl;
	b+=a;
	cout<<b<<endl;
	cin>>b;
	cout<<b<<endl;
	if (b>a) cout<<"b>a"<<endl;
	if (b<a) cout<<"b<a"<<endl;
	b=a+b;
	cout<<b<<endl;
	return 0;
}

