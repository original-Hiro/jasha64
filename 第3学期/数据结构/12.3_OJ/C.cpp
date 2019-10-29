#include <iostream>
#include <cmath>
using namespace std;

const int N = 100001;
int siz[N], sizcnt[N], cntsum[N];
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int v, int u, int j) {to[j] = u; Next[j] = Head[v]; Head[v] = j;}
void DFS(int v, int fa)
{
    siz[v] = 1;
    for (int i = Head[v]; i != 0; i = Next[i])
    {
        int u = to[i];
        if (u == fa) continue;
        DFS(u, v); siz[v] += siz[u];
    }
    sizcnt[siz[v]]++;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1, j = 2, v, u; i < n; i++) {cin >> v >> u; AddEdge(v, u, j++); AddEdge(u, v, j++);}

    DFS(1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i) cntsum[i] += sizcnt[j];

    cout << 1;
    for (int i = n-1; i > 0; i--)
        if (n % i == 0 && cntsum[i] == n / i) cout << ' ' << n / i;
    cout << endl;
    return 0;
}
//此题还有另一种做法，复杂度O(n*sqrt(n))
//枚举因数，每个因数一次DFS检验 

