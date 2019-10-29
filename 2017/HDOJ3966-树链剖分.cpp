#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int N = 50007;
int a[N];

struct Edge {int t, Next;} e[N << 1];
int Head[N];
inline void AddEdge(int a, int b, int& Top)
{
    e[Top].t = b;
    e[Top].Next = Head[a]; Head[a] = Top++;
}

#define lo  o<<1
#define ro  o<<1|1
#define lson  o<<1,     l, m
#define rson  o<<1|1, m+1, r
const int MAXM = 1<<17|1;
int sumv[MAXM], addv[MAXM], n;
void Maintain(int o, int l, int r)
{
    sumv[o] = 0;
    if (r > l) sumv[o] += sumv[lo] + sumv[ro];
    sumv[o] += addv[o] * (r-l+1);
}
void SG_Add(int o, int l, int r, const int ll, const int rr, const int v)
{
    if (ll <= l && r <= rr) addv[o] += v;
    else {
        int m = (l+r)>>1;
        if (ll <= m) SG_Add(lson, ll, rr, v);
        if (rr >  m) SG_Add(rson, ll, rr, v);
    }
    Maintain(o, l, r);
}
int SG_Query(int o, int l, int r, const int v, int delta)
{
    if (l == r) return delta + sumv[o];
    int m = (l+r)>>1;
    if (v <= m) return SG_Query(lson, v, delta + addv[o]);
    else return SG_Query(rson, v, delta + addv[o]);
}
inline void SG_Add(int l, int r, const int v) {SG_Add(1, 1, n, l, r, v);}
inline int SG_Query(int v) {return SG_Query(1, 1, n, v, 0);}

int siz[N], fa[N], son[N], dep[N], top[N], tid[N], DFN;
void DFS1(int v)
{
    siz[v] = 1; son[v] = 0;
    for (int i = Head[v]; i; i = e[i].Next)
    {
        int u = e[i].t;
        if (u == fa[v]) continue;
        fa[u] = v; dep[u] = dep[v] + 1; DFS1(u); siz[v] += siz[u];
        if (siz[u] > siz[son[v]]) son[v] = u;
    }
}
void DFS2(int v, int f)
{
    top[v] = f; tid[v] = ++DFN;
    if (son[v] == 0) return;
    DFS2(son[v], f);
    for (int i = Head[v]; i; i = e[i].Next)
    {
        int u = e[i].t;
        if (u == fa[v] || u == son[v]) continue;
        DFS2(u, u);
    }
}
void Add(int x, int y, const int v)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        int f = top[x];
        SG_Add(tid[f], tid[x], v);
        x = fa[f];
    }
    if (dep[x] > dep[y]) swap(x, y);
    SG_Add(tid[x], tid[y], v);
}
inline int Query(int v) {return SG_Query(tid[v]);}

int main()
{
    int m, q;
    ios::sync_with_stdio(false);
    srand(time(NULL));
    while (cin >> n >> m >> q)
    {
        fill(Head, Head + N, 0);
        fill(sumv, sumv + MAXM, 0);
        fill(addv, addv + MAXM, 0);
        DFN = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 0, j = 2, a, b; i < m; i++)
        {
            cin >> a >> b;
            AddEdge(a, b, j); AddEdge(b, a, j);
        }
        int r = rand() % n + 1;
        dep[r] = 1; fa[r] = 0; DFS1(r); DFS2(r, r);
        for (int i = 1; i <= n; i++) Add(i, i, a[i]);
        char argv;
        int a, b, c;
        while (q--)
        {
            cin >> argv;
            if (argv == 'I') {cin >> a >> b >> c; Add(a, b, c);}
            else if (argv == 'D') {cin >> a >> b >> c; Add(a, b, -c);}
            else {cin >> a; cout << Query(a) << endl;}
        }
    }
    return 0;
}

