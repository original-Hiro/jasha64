#include <fstream>
using namespace std;

ifstream cin("prime.in");
ofstream cout("prime.out");

int main()
{
	int x;
	int i;
	
	cin >> x;
	for (i = 2;; i++)
		if (x % i == 0)
		{
			cout << x / i << endl;
			return 0;
		}
		
	return 0;
}

