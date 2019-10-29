#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cstddef>
using namespace std;

typedef pair<int, int> pii;
const int N = 1001, H = 999979;
pii pt[N];
struct piiHash
{
    size_t operator () (pii a) const {return (a.first * a.first + a.second * a.second) % H;}
};
unordered_set<pii, piiHash> tb;
inline void Assign(pii p1, pii p2, pii& p3, pii& p4, int dx, int dy)
{
    p3.first = p1.first + dx; p3.second = p1.second + dy;
    p4.first = p2.first + dx; p4.second = p2.second + dy;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {cin >> pt[i].first >> pt[i].second; tb.insert(pt[i]);}

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            pii p1 = pt[i], p2 = pt[j], p3, p4;
            int dx = -(p2.second - p1.second), dy = p2.first - p1.first;
            Assign(p1, p2, p3, p4, dx, dy);
            if (tb.find(p3) != tb.end() && tb.find(p4) != tb.end()) res++;
            Assign(p1, p2, p3, p4, -dx, -dy);
            if (tb.find(p3) != tb.end() && tb.find(p4) != tb.end()) res++;
        }
    cout << res / 4 << endl;
    return 0;
}

