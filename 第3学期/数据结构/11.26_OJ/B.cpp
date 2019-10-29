//统计子树大小并不一定需要建树，我们只需要知道子树的大小就等于子树在前(中)序遍历 
//序列中对应的序列长度相等即可 
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2001;
int PreOrder[N], InOrder[N];
int siz[N];
void Count(int l1, int r1, int l2, int r2)
{
    if (l1 == r1) return;
    int rv = PreOrder[l1];
    siz[rv] = r1 - l1;
    int pos = find(InOrder + l2, InOrder + r2, rv) - InOrder, len = pos - l2;
    Count(l1 + 1, l1 + 1 + len, l2, pos);
    Count(l1 + 1 + len, r1, pos + 1, r2);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> PreOrder[i];
    for (int i = 0; i < n; i++) cin >> InOrder[i];

    Count(0, n, 0, n);
    if (n > 0) cout << siz[1];
    for (int i = 2; i <= n; i++) cout << ' ' << siz[i];
    cout << endl;
    return 0;
}

