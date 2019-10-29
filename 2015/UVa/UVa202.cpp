#include <iostream>
#include <algorithm>
using namespace std;

const int M = 3005;
int a[M], b[M], c[M];

int main()
{
	int n, m;
	int count, i;
	
	while (cin >> n >> m)
	{
		fill(a, a + M, 0);
		fill(b, b + M, 0);
		cout << n << '/' << m << " = " << n / m << '.';
		n %= m;
		count = 1;
		
		while (n && !b[n])
		{
			b[n] = count;
			c[count] = n;
			n *= 10;
			a[count++] = n  / m;
			n %= m;
		}		
		
		for (i = 1; i < count && i <= 50; i++)
		{
			if (c[i] == n && n) cout << '(';
			cout << a[i];
		}
		if (!n) cout << "(0";
		if (count > 50) cout << "...";
		cout << ')' << endl << "   " << (n? count - b[n]: 1)
		<< " = number of digits in repeating cycle" << endl << endl;
	}
	
	return 0;
}

