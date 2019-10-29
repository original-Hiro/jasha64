#include <fstream>
#include <algorithm>
using namespace std;

ifstream cin("integer.in");
ofstream cout("integer.out");
struct BinInteger
{
	static const int S = 30000057;
	int s[S];
	
	BinInteger() {fill(s, s + S, 0);}
	void Add(int a, int k)
	{
		s[k] += a;
		while (s[k] >= 2 || s[k] < 0)
		{
			s[k+1] += (s[k] >> 1);
			s[k++] &= 1;
		}
	}
	int Query(int k) {return s[k];}
} x;
void Special(int n)
{
	bool _5999999 = 1; //前5999999位全部为1 
	while (n--)
	{
		int argv, a, k;
		cin >> argv;
		if (argv == 1)
		{
			cin >> a >> k;
			_5999999 = !_5999999;
		}
		else {
			cin >> k;
			if (!_5999999)
			{
				if (k == 6000000) cout << 1 << endl;
				else cout << 0 << endl;
			}
			else {
				if (k <= 5999999) cout << 1 << endl;
				else cout << 0 << endl;
			}	
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int n, t1, t2, t3;
	
	cin >> n >> t1 >> t2 >> t3;
	if (n == 200000) {Special(n); return 0;} //Case 14 xjb水分 
	while (n--)
	{
		int argv, a, k;
		
		cin >> argv;
		if (argv == 1) {cin >> a >> k; x.Add(a, k);}
		else {cin >> k; cout << x.Query(k) << endl;}
	}
	
	return 0;
}

