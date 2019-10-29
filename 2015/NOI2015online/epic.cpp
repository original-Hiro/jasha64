#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Queue
{
	int Data[200007];
	int Front, Rear;
	
	Queue() {Front = Rear = 0;}
	void push(const int& x) {Data[Rear++] = x;}
	void pop() {Front++;}
	int& front() {return Data[Front];}
	bool empty() {return Front == Rear;}
	int& operator [] (const int& x) {return Data[x];}
} q;
struct MYJ_Array
{
	int Data[10];
	int Top;
	
	MYJ_Array() {Top = 0;}
	void push(const int& x) {Data[Top++] = x;}
	bool empty() {return !Top;}
	int& operator [] (const int& x) {return Data[x];}
};
struct HuffmanNode
{
	long long Weight;
	int Parent, Layer;
	MYJ_Array Children;
	
	HuffmanNode() {Weight = Parent = Layer = 0;}
	friend bool operator < (const HuffmanNode& a, const HuffmanNode& b)
	{
		return a.Weight < b.Weight;
	}
	friend bool operator <= (const HuffmanNode& a, const HuffmanNode& b)
	{
		return a.Weight <= b.Weight;
	}
} t[200007];

int main()
{
	freopen("epic.in", "r", stdin);
	freopen("epic.out", "w", stdout);
	
	int n, k, i;
	cin >> n >> k;
	for (i = 1; i <= n; i++) scanf("%lld", &t[i].Weight);
	if (k != 2)
	{
		while (n % (k - 1)) n++;
		n++;
	}
	
	int m, j, s[17] = {0}, Top, Top1 = 1, Top2 = n + 1;
	if (k != 2) m = n + n / (k - 1);
	else m = (n << 1) - 1;
	t[0].Weight = 10000000000000007;
	t[0].Layer = -1;
	sort(t + 1, t + n + 1);
	for (i = n + 1; i <= m; i++)
	{
		for (Top = 0; Top < k; Top++)
			if (Top2 >= i || (Top1 <= n && t[Top1] <= t[Top2])) s[Top] = Top1++;
			else s[Top] = Top2++;
		for (j = 0; j < k; j++)
		{
			t[i].Weight += t[s[j]].Weight;
			t[s[j]].Parent = i;
			t[i].Children.push(s[j]);
		}
	}
	int c;
	q.push(m);
	while (!q.empty())
	{
		c = q.front(); q.pop();
		t[c].Layer = t[t[c].Parent].Layer + 1;
		if (t[c].Children.empty()) continue;
		for (i = 0; i < k; i++) q.push(t[c].Children[i]);
	}
	
	int Res2 = 0;
	long long Res1 = 0;
	for (i = 1; i <= n; i++)
	{
		Res1 += t[i].Layer * t[i].Weight;
		Res2 = max(Res2, t[i].Layer);
	}
	cout << Res1 << endl << Res2 << endl;
	
	return 0;
}

