#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100001;
int n, m, cost[N]; //cost: 1e9
bool Can(const long long val)
{
    int cnt = 0;
    long long cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur + cost[i] > val)
        {
            if (++cnt >= m) return false;
            cur = 0;
        }
        cur += cost[i];
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> cost[i];

    long long Low = *max_element(cost, cost+n), High = 1e14, Res = High;
    while (Low <= High)
    {
        long long Mid = (Low + High) / 2;
        if (Can(Mid)) {Res = Mid; High = Mid - 1;}
        else Low = Mid + 1;
    }

    cout << Res << endl;
    return 0;
}

