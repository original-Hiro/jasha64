#include <iostream>
using namespace std;

const int N = 10007;
int n, a[N], mx[N], Res;

void DFS(int x)
{ 
	if (mx[x - 3] + mx[x - 2] + mx[x - 1] != a[x - 2]) return;
	if (x == n + 2) {++Res; return;}
	if (x <= n) {mx[x] = 1; DFS(x + 1);}
	mx[x] = 0; DFS(x + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	if (n == 1) {cout << 1 << endl; return 0;}
	mx[1] = mx[2] = 1;
	DFS(3);
	mx[1] = mx[2] = 0;
	DFS(3);
	mx[1] = 1; mx[2] = 0;
	DFS(3);
	mx[2] = 1; mx[1] = 0;
	DFS(3);
	
	cout << Res << endl;
	
	return 0;
}

