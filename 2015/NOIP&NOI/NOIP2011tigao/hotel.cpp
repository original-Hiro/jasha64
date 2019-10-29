#include<fstream>
#include<algorithm>
using namespace std;

ifstream cin("hotel.in");
ofstream cout("hotel.out");
const int N = 51;
int available[N], number[N];

int main()
{
	int n, k, p;
	int i, color, money;
	long long ans = 0;
	
	cin >> n >> k >> p;
	for (i = 1; i <= n; i++)
	{
		cin >> color >> money;
		if (money <= p) copy(number, number + N, available);
		ans += available[color];
		if (money <= p) available[color]++;
		number[color]++;
	}
	
	cout << ans << endl;
	
	return 0;
}

