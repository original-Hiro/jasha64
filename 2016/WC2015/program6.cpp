#include <fstream>
using namespace std;

ifstream cin("program6.in");
ofstream cout("program6.out");
unsigned long long a, b, c;
inline void rd(unsigned long long& t) {t = (t * t * a + b) % c;}

int main()
{
	unsigned long long t1, t2, k, n, len;
	
	for (int i = 0; i < 10; i++)
	{
		cin >> n >> a >> b >> c;
		
		t1 = t2 = len = 0;
		do {rd(t1); rd(t2); rd(t2); ++len;} while (t1 != t2);
		n %= len; t1 = 0;
		for (k = 1; k <= n; k++) rd(t1);
		
		cout << t1 << endl;
	}
	
	return 0;
}

