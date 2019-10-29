#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <iterator>
using namespace std;

const int N = 100007;
struct City
{
	int n, h;
	friend bool operator < (const City& a, const City& b) {return a.h < b.h;}
} c[N];
set<City> s;
set<City>::iterator I;
int h[N], f1[N], f2[N];
struct Data
{
	int d;
	long long a, b, x;
	Data() {d = a = b = x = 0;}
} f[N][18];

template <typename T> inline T Abs(T x) {return x < 0 ? -x : x;}
inline int Dist(int a, int b) {return Abs(h[a] - h[b]);}
inline int Dist(set<City>::iterator A, set<City>::iterator B) {return Abs(A -> h - B -> h);}
inline int Dist(int a, set<City>::iterator I) {return Abs(h[a] - I -> h);}
void Special_Work()
{
	int i;
	scanf("%*d%*d");
	cout << 1 << endl;
	cin >> i;
	while (i--) printf("0 0\n");
}
inline void Update(int i, int j)
{
	if (f1[i] == -1 || Dist(i, j) < Dist(i, f1[i]) ||
	(Dist(i, j) == Dist(i, f1[i]) && h[j] < h[f1[i]])) {f2[i] = f1[i]; f1[i] = j;}
	else if (f2[i] == -1 || Dist(i, j) < Dist(i, f2[i]) ||
	(Dist(i, j) == Dist(i, f2[i]) && h[j] < h[f2[i]])) f2[i] = j;
}
inline void Update(int i, set<City>::iterator I)
{
	if (f1[i] == -1 || Dist(i, I) < Dist(i, f1[i]) ||
	(Dist(i, I) == Dist(i, f1[i]) && I -> h < h[f1[i]])) {f2[i] = f1[i]; f1[i] = I -> n;}
	else if (f2[i] == -1 || Dist(i, I) < Dist(i, f2[i]) ||
	(Dist(i, I) == Dist(i, f2[i]) && I -> h < h[f2[i]])) f2[i] = I -> n;
}

int main()
{
	int n, m, x0, i, j, k, x, s0 = 0;
	long long a, b, A = 0, B = 0;
	
	cin >> n;
	if (n == 1) {Special_Work(); return 0;}
	for (i = 1; i <= n; ++i) {scanf("%d", &h[i]); c[i].h = h[i]; c[i].n = i;}
	s.insert(c[n]);
	f1[n - 1] = n; s.insert(c[n - 1]);
	if (n <= 4)
		for (i = n - 2; i > 0; --i)
		{
			f1[i] = f2[i] = -1;
			for (j = i + 1; j <= n; ++j) Update(i, j);
		}
	else {
		s.insert(c[n - 2]); s.insert(c[n - 3]);
		for (i = n - 2; i > n - 4; --i)
		{
			f1[i] = f2[i] = -1;
			for (j = i + 1; j <= n; ++j) Update(i, j);
		}
		for (i = n - 4; i > 0; --i)
		{
			f1[i] = f2[i] = -1;
			s.insert(c[i]);
			I = s.find(c[i]);
			if ((++I) != s.end())
			{
				Update(i, I);
				if ((++I) != s.end()) {Update(i, I); --I;}
				--I;
			}
			if (I != s.begin())
			{
				Update(i, --I);
				if (I != s.begin()) Update(i, --I);
			}
		}
	}
	for (i = n - 2; i > 0; --i)
	{
		f[i][0].d = f1[f2[i]];
		f[i][0].x = Dist(f1[f2[i]], f2[i]) + Dist(f2[i], i);
		f[i][0].b = Dist(f1[f2[i]], f2[i]);
		f[i][0].a = Dist(f2[i], i);
	}
	for (j = 1; (1 << j) < n; ++j)
		for (i = 1; i + (1 << j) <= n; ++i)
		{
			if (!(f[i][j].d = f[f[i][j - 1].d][j - 1].d)) continue;
			f[i][j].a = f[f[i][j - 1].d][j - 1].a + f[i][j - 1].a;
			f[i][j].b = f[f[i][j - 1].d][j - 1].b + f[i][j - 1].b;
			f[i][j].x = f[f[i][j - 1].d][j - 1].x + f[i][j - 1].x;
		}
	
	cin >> x0;
	for (i = n; i > 0; --i)
	{
		x = a = b = 0;
		k = i;
		for (j = 17; j >= 0; --j)
			if (f[k][j].d && x + f[k][j].x <= x0)
				{a += f[k][j].a; b += f[k][j].b; x += f[k][j].x; k = f[k][j].d;}
		if (f2[k] && x + Dist(k, f2[k]) <= x0) {a += Dist(k, f2[k]); x += Dist(k, f2[k]);}
		if (!s0 || (b && !B) || a * B < b * A || (a * B == b * A && h[i] > h[s0])) {A = a; B = b; s0 = i;}
	}
	cout << s0 << endl;
	
	cin >> m;
	while (m--)
	{
		scanf("%d%d", &k, &x0);
		x = a = b = 0;
		for (j = 17; j >= 0; --j)
			if (f[k][j].d && x + f[k][j].x <= x0)
				{a += f[k][j].a; b += f[k][j].b; x += f[k][j].x; k = f[k][j].d;}
		if (f2[k] && x + Dist(k, f2[k]) <= x0) {a += Dist(k, f2[k]); x += Dist(k, f2[k]);}
		printf("%lld %lld\n", a, b);
	}
	
	return 0;
}

