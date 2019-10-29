#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
const int N = 10007, INF = 200007;
int n, s, t;
int f[N];
bool done[N];
vector<int> G[N], C[N];
struct HeapNode
{
    int u;
    HeapNode(int a) {u = a;}
    friend bool operator < (const HeapNode& a, const HeapNode& b) {return f[a.u] > f[b.u];}
};
 
inline void AddEdge(int from, int to)
{
    G[from].push_back(to);
    C[to].push_back(from);
}
void Dijkstra()
{
    int i, u;
    priority_queue<HeapNode> q;
     
    fill(f + 1, f + s, INF);
    fill(f + s + 1, f + n + 1, INF);
    q.push(HeapNode(s));
    while (!q.empty())
    {
        u = q.top().u; q.pop();
        if (done[u]) continue;
        done[u] = true;
        for (i = 0; i < G[u].size(); i++)
            if (f[u] + 1 < f[G[u][i]])
            {
                f[G[u][i]] = f[u] + 1;
                q.push(HeapNode(G[u][i]));
            }
    }
}
 
int main()
{
    int m, l, r;
    int i;
     
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
        AddEdge(l, r);
    }
    cin >> s >> t;
    
    Dijkstra();
     
    if (f[t] == INF) cout << -1 << endl;
    else cout << f[t] << endl;
     
    return 0;
}

