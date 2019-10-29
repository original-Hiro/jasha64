#include <iostream>
#include <iomanip>
using namespace std;

class largeint
{
public:
	largeint(int v = 0)
	{
		size = 0;
		do {
			s[size++] = v % B;
			v /= B;
		} while (v > 0);
	}
	friend largeint operator * (const largeint& a, int b) //b <= 100
	{
		largeint res;
		for (int i = 0, c = 0; i < a.size; i++)
		{
			res[i] = c + a[i] * b;
			c = res[i] / B; res[i] %= B;
			res[a.size] = c;
		}
		res.size = a.size + (res[a.size] != 0);
		return res;
	}
	friend ostream& operator << (ostream& output, const largeint& b)
	{
		output << b[b.size - 1];
		for (int i = b.size - 2; i >= 0; i--) output << setw(W) << setfill('0') << b[i];
		return output;
	}
private:
	static const int S = 51, W = 4, B = 10000;
	int s[S], size;
	int& operator [] (int x) {return s[x];}
	const int& operator [] (int x) const {return s[x];}
} f[101];

int main()
{
	f[1] = 1;
	for (int i = 2; i <= 100; i++) f[i] = f[i-1] * i;
	
	int T;
	cin >> T;
	while (T--)
	{
		int c;
		cin >> c;
		cout << f[c] << endl;
	}
	
	return 0;
}

