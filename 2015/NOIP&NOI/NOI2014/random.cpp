#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 5007;
int a, b, c, d, n, m;
int t[N * N], Plate[N][N];

struct Square
{
	int Value, x, y;
	
	Square() {Value = x = y = 0;}
	Square(int a, int b, int c) {Value = a; x = b; y = c;}
	
	friend bool operator < (const Square& a, const Square& b) {return a.Value > b.Value;}
} Cur, Pos[N << 1];
priority_queue<Square> Q;
inline int Next(const long long& Prev) {return (a * Prev * Prev + b * Prev + c) % d;}

int main()
{
	int x0, q;
	int i, j, k = 1, Top = 1;
	bool OK;
	
	cin >> x0 >> a >> b >> c >> d >> n >> m;
	Plate[0][m] = x0;
	for (i = 1; i <= n; i++)
	{
		Plate[i][1] = Next(Plate[i - 1][m]);
		for (j = 2; j <= m; j++) Plate[i][j] = Next(Plate[i][j - 1]);
	}
	for (i = 1; i <= n * m; i++) t[i] = i;
	for (i = 1; i <= n * m; i++)
		if (i % m == 0) swap(t[i], t[Plate[i / m][m] % i + 1]);
		else swap(t[i], t[Plate[i / m + 1][i % m] % i + 1]);
	cin >> q;
	while (q--) {scanf("%d%d", &i, &j); swap(t[i], t[j]);}
	i = j = 0;
	while (i != n && j != m && k != n * m)
	{
		Plate[i + 1][j + 1] = t[k++];
		Q.push(Square(Plate[i + 1][j + 1], i + 1, j + 1));
		j++;
		if (j % m == 0) j = 0, i++;
	}
	Plate[i + 1][j + 1] = t[k];
	Q.push(Square(Plate[i + 1][j + 1], i + 1, j + 1));
	
	cout << 1;
	Pos[0] = Q.top(); Q.pop();
	while (Top < n + m - 1)
	{
		OK = true;
		Cur = Q.top(); Q.pop();
		
		for (i = 0; i < Top; i++)
			if ((Cur.x < Pos[i].x && Cur.y > Pos[i].y) ||
			(Cur.x > Pos[i].x && Cur.y < Pos[i].y)) {OK = false; break;}
		if (!OK) continue;
				
		printf(" %d", Cur.Value);
		
		Pos[Top++] = Cur;
	}
	cout << endl;
	
	return 0;
}

