//把每一行分别排序，初始取每行最小的元素构成一个序列 
//每次统计答案后，取出序列中最小的元素，再把其所在行的下一个元素加进来 
#include <cstdio>
#include <cctype>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
inline int Read()
{
    int r = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
    return r;
}

const int N = 1001;
int a[N][N];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) a[i][j] = Read();
    	sort(a[i], a[i]+m);
	}

	int pos[N] = {};
    int mx = 0, res;
    for (int i = 0; i < n; i++) {pq.push(pii(a[i][0], i)); mx = max(mx, a[i][0]);}
    res = mx - pq.top().first;
    while (true)
    {
        pii cur = pq.top(); pq.pop();
        int row = cur.second;
        if (pos[row] == m-1) break;
        pos[row]++; mx = max(mx, a[row][pos[row]]); pq.push(pii(a[row][pos[row]], row));
        res = min(res, mx - pq.top().first);
    }

    printf("%d\n", res);
    return 0;
}

