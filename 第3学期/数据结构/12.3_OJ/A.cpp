#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 101, dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int h[N][N];
bool vis[N][N];
struct Square
{
    int x, y;
    Square(int x = 0, int y = 0): x(x), y(y) {}
    friend bool operator < (const Square& a, const Square& b) {return h[a.x][a.y] > h[b.x][b.y];}
};
priority_queue<Square> pq;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++) cin >> h[x][y];

    for (int x = 1; x <= n; x++)
	{
		pq.push(Square(x, 1)); vis[x][1] = 1;
		pq.push(Square(x, m)); vis[x][m] = 1;
	}
    for (int y = 2; y < m; y++)
	{
		pq.push(Square(1, y)); vis[1][y] = 1;
		pq.push(Square(n, y)); vis[n][y] = 1;
	}
    int res = 0, cur = 0;
    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y; pq.pop();
        cur = max(cur, h[x][y]);
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (vis[nx][ny]) continue; //我们需要在统计答案之前判断vis，否则将重复统计 
            if (h[nx][ny] < cur) res += cur - h[nx][ny];
            pq.push(Square(nx, ny)); vis[nx][ny] = 1; //对应地，统计完答案就要做好vis标记 
        }
    }

    cout << res << endl;
    return 0;
}

