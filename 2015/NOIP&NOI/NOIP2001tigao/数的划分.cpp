#include <iostream>
using namespace std;
 
int f[207][7][207];
int dp(int x, int k, int l)
{
    if (k == 1) return 1;
    if (f[x][k][l]) return f[x][k][l];
    for (int i = l; i <= (x >> 1); ++i) f[x][k][l] += dp(x - i, k - 1, i);
    return f[x][k][l];
}
 
int main()
{
    int n, k;
     
    cin >> n >> k;
     
    cout << dp(n, k, 1) << endl;
     
    return 0;
}

