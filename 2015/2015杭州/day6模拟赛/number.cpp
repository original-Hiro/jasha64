#include <fstream>
using namespace std;

ifstream cin("number.in");
ofstream cout("number.out");

int main()
{
	int T;
	long long n, k, i;
	
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		
		for (i = 2; i <= k; i++)
			if (n % i) n = (n / i + 1) * i;
		
		cout << n << endl;
	}
	
	return 0;
}

