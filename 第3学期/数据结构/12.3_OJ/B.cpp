#include <iostream>
using namespace std;

const int N = 100001;
int data[N];
int to[N+N], Head[N], Next[N+N];
inline void AddEdge(int v, int u, int j) {to[j] = u; Next[j] = Head[v]; Head[v] = j;}
bool DFS(int v, int fa)
{
    for (int i = Head[v]; i != 0; i = Next[i])
    {
        int u = to[i];
        if (u == fa) continue;
        if (!DFS(u, v)) return false;
    }
    if (data[v] < 0 || (data[v] == 0 && fa != 0)) return false;
    data[fa] -= data[v]; return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> data[i];
    for (int i = 1, j = 2, v, u; i < n; i++) {cin >> v >> u; AddEdge(v, u, j++); AddEdge(u, v, j++);}

    if (DFS(1, 0)) cout << "^_^" << endl;
    else cout << "QAQ" << endl;
    //for (int i = 1; i <= n; i++) cout << data[i] << ' '; cout << endl;
    return 0;
}

