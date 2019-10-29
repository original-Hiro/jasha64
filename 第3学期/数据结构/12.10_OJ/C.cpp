#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

inline int Read()
{
    int r = 0;
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
    return r;
}
const int N = 4000001;
int n, cost[N];
bool Can(const int val)
{
    for (int i = n-1, j = 1, cnt = 1; i >= 0; i--)
    {
        int diff = val - cost[i];
        if (diff < j) return false;
        else if (diff == j)
        {
            if (--cnt == 0)
            {
                if (i < (j > 31 ? 0x7fffffff : (1 << j-1) - 1)) return true;
                else {j++; cnt = j > 31 ? 0x7fffffff : (1 << j-1) - 1;}
            }
        }
        else {j = diff; cnt = j > 31 ? 0x7fffffff : (1 << j-1) - 1;}
    }
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cost[i] = Read();

    int Low = cost[n-1] + 1, High = cost[n-1] + n - 1, Res = High;
    while (Low <= High)
    {
        int Mid = (Low + High) / 2;
        if (Can(Mid)) {Res = Mid; High = Mid - 1;}
        else Low = Mid + 1;
    }

    cout << Res << endl;
    return 0;
}

