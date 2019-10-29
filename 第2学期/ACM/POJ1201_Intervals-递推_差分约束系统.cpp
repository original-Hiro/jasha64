//用f[N]表示[0, N]区间内取了多少个数，答案等于f[N]-f[-1]的最小值 
//我们用数组d[N]表示[0, N]区间内至少要取多少个数，且令d[-1] = 0，那么答案就是d[N] 
//关系式是d[a-1] + c <= d[b]，固有条件d[i] + 0 <= d[i+1]，d[i+1] - 1 <= d[i]
//符合差分约束系统中的最长路模型，建图跑最长路即可 
#include <iostream>
#include <queue>
using namespace std;

const int N = 50002;
int Head[N];
struct Edge {int w, t, Next;} e[N*3];
int Top = 2;
inline void AddEdge(int S, int T, int W)
{
	e[Top].t = T; e[Top].w = W;
	e[Top].Next = Head[S]; Head[S] = Top++;
}

int d[N];
bool inq[N];
void SPFA()
{
	queue<int> q;
	for (int i = 0; i < N; i++) {q.push(i); inq[i] = 1;}
	while (!q.empty())
	{
		int v = q.front(); q.pop();
		for (int i = Head[v]; i; i = e[i].Next)
		{
			int u = e[i].t;
			if (d[u] < d[v] + e[i].w)
			{
				d[u] = d[v] + e[i].w;
				if (!inq[u]) {q.push(u); inq[u] = 1;}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0, a, b, c; i < n; i++)
	{
		cin >> a >> b >> c;
		AddEdge(a, b+1, c);
	}
	for (int i = 0; i < N-1; i++) {AddEdge(i, i+1, 0); AddEdge(i+1, i, -1);}
	//因为建图时涉及到d[-1]，不好表示，因此我们把整个输入数据向右平移一格 
	
	SPFA();
	
	cout << d[N-1] << endl;
	
	return 0;
}

