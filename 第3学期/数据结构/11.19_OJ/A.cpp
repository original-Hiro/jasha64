#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100001;
int to[N+N], len[N+N], Head[N], Next[N+N];
inline void AddEdge(int s, int t, int w, int i) {to[i] = t; len[i] = w; Next[i] = Head[s]; Head[s] = i;}
int fa[N], dis[N];
void DFS(int v)
{
    for (int i = Head[v]; i != 0; i = Next[i])
    {
        int u = to[i];
        if (u == fa[v]) continue;
        fa[u] = v; dis[u] = dis[v] + len[i]; DFS(u);
    }
}
void Make_Root(int v) {fa[v] = dis[v] = 0; DFS(v);}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1, j = 2, a, b, c; i < n; i++)
    {
        cin >> a >> b >> c;
        AddEdge(a, b, c, j++); AddEdge(b, a, c, j++);
    }

    Make_Root(1);
    int cur = 1;
    for (int i = 2; i <= n; i++)
        if (dis[i] > dis[cur]) cur = i;
    Make_Root(cur);
    cout << *max_element(dis+1, dis+n+1) << endl;
    return 0;
}

