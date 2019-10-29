#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1001, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int len[N][N];
char G[N][N];

int m, n;
void DFS(int x, int y, int dir)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == dir) continue;
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > m || ny < 1 || ny > n) continue;
        if (G[nx][ny] == '#') continue;
        len[nx][ny] = len[x][y] + 1; DFS(nx, ny, 3-i);
    }
}
inline void MakeTree(int x, int y) {len[x][y] = 0; DFS(x, y, -1);}

int main()
{
    cin >> n >> m;
    for (int x = 1; x <= m; x++) scanf("%s", G[x] + 1);

    int rx = -1, ry = -1;
    for (int x = 1; x <= m; x++)
    {
        for (int y = 1; y <= n; y++)
            if (G[x][y] == '.') {rx = x; ry = y; break;}
        if (rx != -1) break;
    }
    if (rx == -1) {cout << 0 << endl; return 0;}
    MakeTree(rx, ry);
    for (int x = 1; x <= m; x++)
        for (int y = 1; y <= n; y++)
            if (len[x][y] > len[rx][ry]) {rx = x; ry = y;}
    MakeTree(rx, ry);

    cout << *max_element(len[0], len[0] + N*N) << endl;
    return 0;
}

