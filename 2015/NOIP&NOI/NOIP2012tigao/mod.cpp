#include <fstream>
using namespace std;

ifstream cin("mod.in");
ofstream cout("mod.out");

void Ext_Gcd(const int& a, const int& b, int& x, int& y)
{
	if (!b) {x = 1; y = 0; return;}
	Ext_Gcd(b, a % b, y, x);
	y -= a / b * x;
}
inline void Correct(int& x, int& b)
{
	while (x > 0) x -= b;
	while (x <= 0) x += b;
}

int main()
{
	int a, b;
	int x, y;
	
	cin >> a >> b;
	
	Ext_Gcd(a, b, x, y); 
	Correct(x, b);
	
	cout << x << endl;
	
	return 0;
}

