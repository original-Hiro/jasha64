#include <fstream>
using namespace std;

ifstream cin("block.in");
ofstream cout("block.out");
int h[100007];

int main()
{
	int n;
	int i, ans, cache;
	
	cin >> n;
	for (i = 1; i <= n; i++) cin >> h[i];
	
	ans = h[1];
	for (i = 2; i <= n; i++)
	{
		if (h[i] >= h[i - 1]) cache = h[i - 1];
		else cache = h[i];
		ans += h[i] - cache;
	}
	
	cout << ans << endl;
	
	return 0;
}

