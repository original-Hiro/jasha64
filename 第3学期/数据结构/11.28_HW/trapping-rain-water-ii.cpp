//leetcode - trapping rain water ii
//搜索 
/*
这道"装水问题"我们采用"模拟海平面上升"的方法来解决，模拟"海平面"上升时漫过较高的 
格子汇入较低的格子的过程 
首先，易见边界上的点无法装水，海平面只要上升到一个边界格子的高度就一定会漫过它 
因为只有海平面的高度到达格子高度时装水的情况可能发生变化，所以只需要从低到高依次 
访问边界上所有的格子 
所以，我们把所有位于边界的点作为BFS的启动点，BFS时每次取出队列中高度最低的点（需 
要使用优先队列）并且维护海平面高度mx为目前已搜过的点中的最高高度 
因为能装水的方格周围的四个方格都比自己高，而且装水高度取决于周围四个方格最低的一 
个（木桶原理），所以每次取出优先队列顶端的点，把周围四个点中未访问过的加入队列 
（亦即模拟海水横向蔓延的过程），且如果这四个点中有比当前点低的，就把和海平面高度 
的差计入答案（亦即模拟海水纵向灌入的过程） 
因为优先队列的设定，较低的格子一定比较高的格子先访问，这样就确保了上面所说木桶原 
理的成立 
*/
class Solution
{
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        if (heightMap.empty() || heightMap[0].empty()) return 0; //判空（否则访问heightMap[0]即报错） 
        priority_queue<Square> pq;
        bool vis[111][111] = {};
        //BFS初始点是地图边界上的点 
        int r = heightMap.size(), c = heightMap[0].size();
        for (int i = 0; i < c; i++)
        {
            pq.push(Square(0, i, heightMap[0][i])); vis[0][i] = 1;
            pq.push(Square(r-1, i, heightMap[r-1][i])); vis[r-1][i] = 1;
        }
        for (int i = 0; i < r; i++)
        {
            pq.push(Square(i, 0, heightMap[i][0])); vis[i][0] = 1;
            pq.push(Square(i, c-1, heightMap[i][c-1])); vis[i][c-1] = 1;
        }
        //搜索并维护"海平面"高度 
        int res = 0, mx = 0;
        while (!pq.empty())
        {
            int curx = pq.top().x, cury = pq.top().y; pq.pop();
            mx = max(mx, heightMap[curx][cury]);
            for (int i = 0; i < 4; i++)
            {
                int nx = curx + dx[i], ny = cury + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                if (heightMap[nx][ny] < mx) res += mx - heightMap[nx][ny];
                pq.push(Square(nx, ny, heightMap[nx][ny]));
            }
        }
        return res;
    }
private:
	static const int dx[4], dy[4];
    struct Square
    {
        int x, y, h;
        Square(int x = 0, int y = 0, int h = 0): x(x), y(y), h(h) {}
        friend bool operator < (const Square& a, const Square& b) {return a.h > b.h;}
    };
};
const int Solution::dx[4] = {-1, 0, 0, 1}, Solution::dy[4] = {0, -1, 1, 0}; //类的常量成员应在类内说明、类外定义 
//参考资料: https://www.cnblogs.com/grandyang/p/5928987.html 

