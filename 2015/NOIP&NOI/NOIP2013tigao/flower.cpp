#include <fstream>
using namespace std;

ifstream cin("flower.in");
ofstream cout("flower.out");
int h[100005];

int main()
{
	int n;
	int i, ans = 1, top = 0, cache;
	
	cin >> n >> h[0];
	for (i = 1; i < n; i++)
	{
		cin >> cache;
		if (cache != h[top]) h[++top] = cache;
	}
	
	for (i = 1; i < n - 1; i++)
		if ((h[i] > h[i - 1] && h[i] > h[i + 1]) ||
		(h[i] < h[i - 1] && h[i] < h[i + 1])) ans++;
	
	if (n >= 2) ans++;
	
	cout << ans << endl;
	
	return 0;
}

