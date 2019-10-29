#include <iostream>
using namespace std;

const bool p[32] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1,
0, 0, 0, 0, 0, 1, 0, 1}; 
int n, Case;
int a[17] = {1};
bool Vis[17];

void DFS(int Cur)
{
	if (Cur == n && p[a[0] + a[n - 1]])
	{
		cout << 1;
		for (int i = 1; i < n; i++) cout << ' ' << a[i];
		cout << endl;
	}
	else {
		for (int i = 2; i <= n; i++)
			if (!Vis[i] && p[i + a[Cur - 1]])
			{
				a[Cur] = i;
				Vis[i] = true;
				DFS(Cur + 1);
				Vis[i] = false;
			}
	}
}

int main()
{
	while (cin >> n)
	{
		if (Case) cout << endl;
		cout << "Case " << ++Case << ':' << endl;
		DFS(1);
	}
	
	return 0;
}

