#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
pii a[100001];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	sort(a, a+n);
	queue<pii> q;
	int b, e, i = 0;
	while (i < n)
	{
		b = a[i].first; e = a[i].second;
		while (i < n-1 && a[i+1].first <= e) {e = max(e, a[i+1].second); i++;}
		q.push(pii(b, e)); i++;
	}
	
	cout << q.size() << endl;
	while (!q.empty()) {cout << q.front().first << ' ' << q.front().second << endl; q.pop();}
	return 0;
}

