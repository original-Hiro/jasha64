#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

const int N = 100007;
int a[N], c[N];
long long s[4000007];
bool v[N];
map<int, int> m;

inline bool Greater(const int& a, const int& b) {return a > b;}

int main()
{
	freopen("k.in", "r", stdin);
	freopen("k.out", "w", stdout);
	
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	copy(a + 1, a + n + 1, c + 1);
	sort(c + 1, c + n + 1);
	int len = unique(c + 1, c + n + 1) - c - 1;
	for (int i = 1; i <= len; i++) m[c[i]] = i;
	int Top = 0;
	bool First;
	for (int i = 1; i <= n; i++)
	{
		fill(v + 1, v + len + 1, false);
		First = true;
		for (int j = i; j <= n; j++)
			if (!v[m[a[j]]])
			{
				v[m[a[j]]] = true;
				if (First) {s[Top + 1] = a[j]; First = false;}
				else s[Top + 1] = s[Top] + a[j];
				++Top;
				if (Top > 4000000) {sort(s + 1, s + Top + 1, Greater); Top = k + 1;}
			}
	}
	sort(s + 1, s + Top + 1, Greater);
	
	printf("%lld\n", s[k]);
	
	return 0;
}

