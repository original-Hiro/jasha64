#include <iostream>
using namespace std;

const int N = 100001, K = 17;
int fa[N], anc[N][K], cnt[N];
int kth(int v, int k)
{
    for (int i = K-1; i >= 0; i--)
        if (k >= (1 << i)) {v = anc[v][i]; k -= 1 << i;}
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int v = 2; v <= n; v++) {cin >> fa[v]; anc[v][0] = fa[v];}
    for (int k = 1; k < K; k++)
        for (int v = 1; v <= n; v++) anc[v][k] = anc[anc[v][k-1]][k-1];

    for (int v = 1; v <= n; v++) cnt[kth(v, k)]++;

    cout << cnt[1];
    for (int i = 2; i <= n; i++) cout << ' ' << cnt[i];
    cout << endl;
    return 0;
}

