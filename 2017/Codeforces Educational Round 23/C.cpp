#include <iostream>
using namespace std;

inline int sum(long long s)
{
	int Ret = 0;
	do {
		Ret += s % 10;
		s /= 10;
	} while (s);
	return Ret;
}

int main()
{
	long long n, s;
	
	cin >> n >> s;
	if (n < s) {cout << 0 << endl; return 0;}
	
	long long i;
	for (i = s; i <= n; i++)
		if (i - sum(i) >= s) break;
	
	cout << n - i + 1 << endl;
	
	return 0;
}

