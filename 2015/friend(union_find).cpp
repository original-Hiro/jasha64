#include <iostream>
#include <algorithm>
using namespace std;

int father[30007], num[30007];

inline int Find(const int& x)
{
	if (father[x] != x) father[x] = Find(father[x]);
	return father[x];
}

int main()
{
	int n, m, a, b;
	int i, cache;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++) father[i] = i;
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b;
		a = Find(a);
		b = Find(b);
		father[a] = b;
	}
	
	for (i = 1; i <= n; i++)
	{
		cache = Find(i);
		num[cache]++;
	}
	
	cout << *max_element(num + 1, num + n + 1) << endl;
	
	return 0;
}

