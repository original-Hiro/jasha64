#include <iostream>
#include <stack>
using namespace std;

const int N = 100007;
struct Edge{int s, t, Num, Next;} e[N << 2];
int Head[N], In[N], Out[N], Top = 2, t, n, m, s;
bool vis[N << 2];
stack<int> Printer;

void DFS(int x, int fa)
{
	for (int& i = Head[x]; i; i = e[i].Next)
	{
		if (vis[i]) continue;
		vis[i] = true; if (t == 1) vis[i ^ 1] = true;
		DFS(e[i].t, i);
	}
	if (fa) Printer.push(e[fa].Num);
}
bool isEuler()
{
	for (int i = 1; i <= n; i++)
		if ((t == 1 && In[i] & 1) || (t == 2 && In[i] != Out[i])) return false;
	return true;
}
inline void AddEdge(int a, int b, int num)
{
	e[Top].s = a; e[Top].t = b; e[Top].Num = num;
	e[Top].Next = Head[a]; Head[a] = Top++;
	++Out[a]; ++In[b];
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> t >> n >> m;
	for (int i = 1, a, b; i <= m; i++)
	{
		cin >> a >> b;
		AddEdge(a, b, i); if (t == 1) AddEdge(b, a, -i);
	}
	
	if (!isEuler()) {cout << "NO" << endl; return 0;}
	else {
		if (!s) s = e[2].s;
		DFS(s, 0);
		if (Printer.size() < m) {cout << "NO" << endl; return 0;}
		cout << "YES" << endl;
		if (Printer.empty()) return 0;
		cout << Printer.top(); Printer.pop();
		while (!Printer.empty()) {cout << ' ' << Printer.top(); Printer.pop();}
		return 0;
	}
	
	return 0;
}

