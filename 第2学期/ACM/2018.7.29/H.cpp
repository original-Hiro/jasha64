#include <iostream>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int N = 101;
bool v[N][N];
char G[N][N];

int main()
{
  ios::sync_with_stdio(false);
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) cin >> G[i];

  int Res = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (G[i][j] == '#' && !v[i][j]) {
	Res++; v[i][j] = 1;
	int x = i, y = j;
	bool Cont = 1;
	while (Cont) {
	  Cont = 0;
	  for (int k = 0; k < 8; k++) {
	    int nx = x + dx[k], ny = y + dy[k];
	    if (G[nx][ny] == '#' && !v[nx][ny]) {
	      v[nx][ny] = 1;
	      Cont = 1; x = nx; y = ny; break;
	    }
	  }
	}
      }

  cout << Res << endl;
  return 0;
}

