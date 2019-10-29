#include <cstdio>
#include <cctype>
#include <algorithm>
#include <ext/pb_ds/priority_queue.hpp>
#include <climits> //INT_MAX等的头文件 
using namespace std;

inline int Read()
{
    int r = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
    return r;
}

const int N = 1001;
struct Item
{
    int val, row;
    friend bool operator < (const Item& a, const Item& b) {return a.val < b.val;}
} a[1000001];
typedef __gnu_pbds::priority_queue<int> HeapG;
HeapG hg; HeapG::point_iterator posg[N];
typedef __gnu_pbds::priority_queue<int, greater<int> > HeapL; //pbds库的优先队列自定义比较方式的写法 
HeapL hl; HeapL::point_iterator posl[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {a[i*m+j].val = Read(); a[i*m+j].row = i;}
    sort(a, a+n*m);

    int acnt = 0, res = INT_MAX;
    for (int i = 0; i < n*m; i++)
    {
        int row = a[i].row, val = a[i].val;
        if (posl[row] == 0) {posg[row] = hg.push(val); posl[row] = hl.push(val); acnt++;} //point_iterator默认值为0 
        else {hg.modify(posg[row], val); hl.modify(posl[row], val);}
        if (acnt == n) res = min(res, hg.top() - hl.top());
    }

    printf("%d\n", res);
    return 0;
}

