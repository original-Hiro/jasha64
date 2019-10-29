#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

const int GOAL[] = {1, 2, 3, 4, 5, 6, 7, 8, 0}, N = 362880, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1},
Fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
const char* dir = "uldr";

template <typename T>
inline T Abs(const T& x)
{
	if (x < 0) return -x;
	return x;
}

int f[N], Top;
bool Vis[N];
char Dir[N];
stack<char> Printer;
struct State
{
	int c[9], A_, sx, sy, s, Num;
	
	void A_Star()
	{
		int c1, x, y, i;
		
		A_ = 0;
		for (i = 0; i < 9; i++)
		{
			c1 = (c[i] + 8) % 9; x = c1 / 3; y = c1 % 3;
			A_ += Abs(x - i / 3) + Abs(y - i % 3);
		}
	}
	
	int& operator [] (const int& x) {return c[x];}
	const int& operator [] (const int& x) const {return c[x];}
	friend bool operator < (const State& a, const State& b) {return a.A_ > b.A_;}
} T, C;
priority_queue<State> pq;

bool Insert(const State& C)
{
	int Res = 0, Count, i, j;
	
	for (i = 0; i < 9; i++)
	{
		Count = 0;
		for (j = 0; j < i; j++)
			if (C[j] > C[i]) Count++;
		Res += Count * Fac[i];
	}
	
	if (Vis[Res]) return false;
	return Vis[Res] = true;
}
void Print()
{
	int c = Top;
	
	do {
		Printer.push(Dir[c]);
		c = f[c];
	} while (c);
	
	while (!Printer.empty()) {printf("%c", Printer.top()); Printer.pop();}
	printf("\n");
}
void Solve()
{
	int i, c, tx, ty, t;
	
	while (!pq.empty())
	{
		T = pq.top(); pq.pop(); c = T.Num;
		for (i = 0; i < 4; i++)
		{
			C = T;
			tx = C.sx + dx[i]; ty = C.sy + dy[i]; t = tx * 3 + ty;
			if (tx < 0 || tx > 2 || ty < 0 || ty > 2) continue;
			swap(C[t], C[C.s]); C.s = t;
			if (memcmp(C.c, GOAL, sizeof(GOAL)) == 0) {f[Top] = c; Dir[Top] = dir[i]; Print(); return;}
			if (!Insert(C)) continue;
			C.sx = tx; C.sy = ty; f[Top] = c; Dir[Top] = dir[i]; C.A_Star(); C.Num = Top++; pq.push(C);
		}
	}
}

int main()
{
	int i, j, NXS;
	char c;
	
	while (scanf(" %c", &c) != EOF)
	{
		fill(Vis, Vis + N, false);
		Top = NXS = 0;
		while (!pq.empty()) pq.pop();
		
		if (c == 'x') {C[0] = 0; C.s = C.sx = C.sy = 0;}
		else C[0] = c - '0';
		for (i = 1; i < 9; i++)
		{
			scanf(" %c", &c);
			if (c == 'x') {C[i] = 0; C.s = i; C.sx = i / 3; C.sy = i % 3;}
			else C[i] = c - '0';
		}
		for (i = 0; i < 9; i++)
			for (j = i + 1; j < 9; j++)
				if (C[i] > C[j] && C[i] && C[j]) NXS++;
		if (NXS & 1) {printf("unsolvable\n"); continue;}
		C.A_Star(); C.Num = Top++; Insert(C); pq.push(C);
		
		Solve();
	}
	
	return 0;
}

