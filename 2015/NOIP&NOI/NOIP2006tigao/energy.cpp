#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("energy.in");
ofstream cout("energy.out");
const int M = 105;
int a[M], f[M][M] = {0};
 
int main()
{
    int n;
    int i, j, k, ans = 0;
     
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
     
    for (k = 1; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = i; j < i + k; j++)
                f[i][(i + k) % n] = max(f[i][(i + k) % n], f[i][j % n] + f[(j + 1) % n][(i + k) % n] + 
                a[i] * a[(j + 1) % n] * a[(i + k + 1) % n]);
    for (i = 0; i < n; i++) ans = max(ans, f[i][(i + n - 1) % n]);
     
    cout << ans << endl;
     
    return 0;
}

