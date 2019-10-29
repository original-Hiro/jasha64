#include <iostream>
using namespace std;

int father[20007];

inline int Find(const int& x)
{
	if (father[x] != x) father[x] = Find(father[x]);
	return father[x];
}

int main()
{
	int n, m, q, a, b;
	int i;
	
	cin >> n >> m;
	for (i = 1; i <= n; i++) father[i] = i;
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b;
		a = Find(a);
		b = Find(b);
		father[a] = b;
	}
	cin >> q; 
	for (i = 1; i <= q; i++)
	{
		cin >> a >> b;
		if (Find(a) == Find(b)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}

