#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000007;
int n;
int f[N];
long long Count[N];

struct MYJ_Stack
{
	int a[N], Top;
	
	MYJ_Stack() {Top = 0;}
	
	void push(const int& x) {a[Top++] = x;}
	int& top() {return a[Top - 1];}
	void pop() {Top--;}
	bool empty() {return !Top;}
} s;
struct Queue
{
	int a[N], Front, Rear;
	
	Queue() {Front = Rear = 0;}
	
	void push(const int& x) {a[Rear++] = x;}
	int& front() {return a[Front];}
	void pop() {Front++;}
	bool empty() {return Front == Rear;}
} q;
struct EdgeT
{
	int From, To, Dist;
	
	EdgeT() {From = To = Dist = 0;}
	EdgeT(const int& a, const int& b, const int& c) {From = a; To = b; Dist = c;}
} Edge[N << 1];
int Top, First[N], Next[N << 1];
template <typename T>
inline T Abs(const T& a)
{
	if (a < 0) return -a;
	return a;
}
inline void AddEdge(const int& From, const int& To, const int& Dist)
{
	Edge[++Top] = EdgeT(From, To, Dist);
	Next[Top] = First[From];
	First[From] = Top;
}
void BFS()
{
	int t, i;
	
	fill(f + 1, f + n + 1, -1);
	q.push(1);
	s.push(1);
	while (!q.empty())
	{
		t = q.front(); q.pop();
		i = First[t];
		while (i)
		{
			if (Edge[i].From == t && Edge[i].To != 1 && f[Edge[i].To] == -1)
				{
					f[Edge[i].To] = t;
					q.push(Edge[i].To);
					s.push(Edge[i].To);
				}
			else if (Edge[i].From != 1 && f[Edge[i].From] == -1)
				{
					f[Edge[i].From] = t;
					q.push(Edge[i].From);
					s.push(Edge[i].From);
				}
			i = Next[i];
		}
	}
	
	while (!s.empty())
	{
		t = s.top(); s.pop();
		Count[f[t]] += Count[t];
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	int From, To, Dist;
	int i;
	long long Res = 0;
	
	cin >> n;
	fill(f + 1, f + n + 1, 0);
	fill(Count + 1, Count + n + 1, 1);
	for (i = 1; i < n; i++)
	{
		scanf("%d%d%d", &From, &To, &Dist);
		AddEdge(From, To, Dist);
		AddEdge(To, From, Dist);
	}
	
	BFS();
	n = (n << 1) - 1;
	for (i = 1; i < n; i += 2)
		if (f[Edge[i].From] == Edge[i].To)
			Res += Abs((Count[Edge[i].From] << 1) - Count[1]) * Edge[i].Dist;
		else Res += Abs((Count[Edge[i].To] << 1) - Count[1]) * Edge[i].Dist;
	
	cout << Res << endl;
	
	return 0;
}

