#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("calc.in");
ofstream cout("calc.out");
int f[1007];

int gcd(int a, int b)
{
	int c;
	while (b) {c = a % b; a = b; b = c;}
	return a;
}

int main()
{
	int a, b, i, j;
	
	cin >> a >> b;
	
	for (i = 1; i <= 1000; i++)
		for (j = 1; i * j <= 1000; j++) f[i * j]++;
	
	cout << f[gcd(a, b)] << endl;
	
	return 0;
}

