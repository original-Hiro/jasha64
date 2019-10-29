#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 107;
int a[N], b[N], n;

inline int Prev(int x) {return (x-1+n) % n;}
inline int Next(int x) {return (x+1) % n;}
bool Less(int b, int c)
{
	if (a[b] != a[c]) return a[b] < a[c];
	return a[Prev(b)] * a[Next(b)] > a[Prev(c)] * a[Next(c)]; 
}

int n1, res, c[N];
void Integrate(int p)
{
	res += a[Prev(p)] * a[p] * a[Next(p)];
	for (int i = 0; i < n1; i++)
		if (b[i] > p) b[i]--;
	copy(a, a+p, c); copy(a+p+1, a+n, c+p); n--; copy(c, c+n, a);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) b[i] = i;
	sort(b, b+n, Less);
	n1 = n;
	for (int i = 0; i < n1-1; i++) Integrate(b[i]);
	
	cout << res << endl;
	
	return 0;
}

