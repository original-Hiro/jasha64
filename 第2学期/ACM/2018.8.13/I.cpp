#include <iostream>
#include <climits>
#include <set>
#include <iterator>
using namespace std;

typedef unsigned int uint;
uint x0, x1, A, B, C;
uint next()
{
	uint t = x0 * A + x1 * B + C;
	x0 = x1; x1 = t;
	return x0 >> 2;
}

int n, q;
multiset<int> S;
int a[10000001];

int main()
{
	cin >> n >> q >> x0 >> x1 >> A >> B >> C;
	for (int i = 0; i < n; i++) a[i] = INT_MAX;
	
	int mn = a[0], sum = n, mx = 0X000FFFFF;
	uint Res = 0, base = 10099;
	for (int i = 1; i <= q; i++)
	{
		int x = next(), y = next(); x %= n;
		if (y <= mx) S.insert(y);
		if (a[x] <= mx) S.erase(S.find(a[x]));
		if (a[x] == mn) sum--;
		if (y < mn) {mn = y; sum = 1;}
		else if (y == mn) sum++;
		a[x] = y;
		if (!sum)
		{
			if (!S.empty())
			{
				sum = 0; mn = *S.begin();
				for (multiset<int>::iterator I = S.begin(); I != S.end(); I++)
					if (*I == mn) sum++;
					else break;
			}
			else {
				mn = INT_MAX; sum = 0;
				for (int i = 0; i < n; i++)
					if (a[i] < mn) {mn = a[i]; sum = 1;}
					else if (a[i] == mn) sum++;
			}
		}
		Res += mn * base; base *= 10099;
	}
	
	cout << Res << endl;
	return 0;
}

