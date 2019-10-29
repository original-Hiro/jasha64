#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>
#include <deque>

using namespace std;

const int maxn = 50007, inf = 0x3fffffff;

struct Edge{
	int u, t;
	Edge(int x1, int y1){u = x1; t = y1;}
};

int dfn[maxn] = { }, low[maxn] = { }, d[maxn] = { }, vis[maxn] = { };
int scc = 0, idx = 0, component[maxn] = { };
int n, m, k;
bool inq[maxn] = { };
vector<Edge> e[maxn], e_[maxn];
stack<int> s;

void tarjan(int u)
{
	dfn[u] = low[u] = ++idx;
	vis[u] = 2;
	s.push(u);
	for(vector<Edge> :: iterator I = e[u].begin(); I != e[u].end(); I++)
	{
		int v = (*I).u;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[v] == 2)
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
	if(dfn[u] == low[u])
	{
		scc++;
		int v;
		do{
			v = s.top();
			s.pop();
			component[v] = scc;
			vis[v] = 1;
		}while(u != v);
	}
}

void spfa(int source)
{
	deque<int> dq;
	int u, v;
	fill(d, d + n + 1, inf);
	d[source] = 0;
	dq.push_back(source);
	inq[source] = true;
	while(!dq.empty())
	{
		u = dq.front();
		dq.pop_front();
		inq[u] = false;
		for(vector<Edge> :: iterator I = e_[u].begin(); I != e_[u].end(); ++I)
		{
			v = (*I).u;
			if(d[u] < inf && d[u] + (*I).t < d[v])
			{
				d[v] = d[u] + (*I).t;
				if(!inq[v])
				{
					inq[v] = true;
					if(!dq.empty())
					{
						if(d[v] > d[dq.front()])dq.push_back(v);
						else dq.push_front(v);
					}
					else dq.push_back(v);
				}
			}
		}
	}
} 

int main()
{
	ios :: sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		e[x].push_back(Edge(y, z));
	}
	for(int i = 1; i <= n; i++)
	{
		if(!dfn[i])
			tarjan(i);
	}
	for(int i = 1; i <= n; i++)
	{
		for(vector<Edge> :: iterator I = e[i].begin(); I != e[i].end(); ++I)
		{
			if(component[i] == component[(*I).u]) continue;
			e_[component[i]].push_back(Edge(component[(*I).u], (*I).t));
		}
	}
	spfa(component[1]);
	cout << d[component[k]] << endl;
	return 0;
}
