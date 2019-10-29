#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int a[107];

int main()
{
	int n, m, i, j, c;
	bool Finished = false;
	
	cin >> n >> m;
	for (i = 0; i < n; i++) {cin >> c; q.push(c);}
	
	for (i = 0; i < m; i++) {a[i] = q.front(); q.pop();}
	for (i = 1;; i++)
	{
		Finished = true;
		for (j = 0; j < m; j++)
			if (a[j])
			{
				a[j]--;
				if (!a[j] && !q.empty()) {a[j] = q.front(); q.pop(); Finished = false;}
				if (a[j]) Finished = false;
			}
		if (Finished) {cout << i << endl; return 0;}
	}
	
	return 0;
}

