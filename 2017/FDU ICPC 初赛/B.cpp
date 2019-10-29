#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const long long A[] = {0, 1, 2, 4, 16, 256, 65536};

int main()
{
	string s;
	long long n;
	
	while (cin >> s)
	{
		if (s.size() > 10) {cout << "KILL la KILL" << endl; continue;}
		istringstream ss(s);
		ss >> n;
		if (n > A[6] * A[6]) {cout << "KILL la KILL" << endl; continue;}
		if (n == 1) cout << 0 << endl;
		else {
			bool OK = 0;
			for (int i = 1; i <= 5; i++)
				if (A[i] * A[i] <= n && n < A[i+1] * A[i+1]) {cout << i << endl; OK = 1; break;}
			if (!OK) cout << "KILL la KILL" << endl;
		}
	}
	
	return 0;
}

