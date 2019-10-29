#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100001;
int n, sp[N], cost[N];
long long tot;
bool Can(const long long val)
{
    long long rem = tot;
    for (int i = 0; i < n; i++)
        if (val > sp[i] && (rem -= cost[i] * (val - sp[i])) < 0) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> tot;
    for (int i = 0; i < n; i++) cin >> sp[i] >> cost[i];

    long long Low = *min_element(sp, sp+n), High = 2e12, Res = Low;
    while (Low <= High)
    {
        long long Mid = (Low + High) / 2;
        if (Can(Mid)) {Res = Mid; Low = Mid + 1;}
        else High = Mid - 1;
    }

    cout << Res << endl;
    return 0;
}

