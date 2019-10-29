#include <iostream>
using namespace std;

int main()
{
	int n, i = 2, j, a = 1, b = 2;
	
	cin >> n;
	
	if (n == 1) cout << "1/1" << endl;
	while (i < n)
		if (a == 1)
		{
			while (b > 1 && i < n) {++a; --b; ++i;}
			if (i < n) {++a; ++i;}
		}
		else {
			while (a > 1 && i < n) {--a; ++b; ++i;}
			if (i < n) {++b; ++i;}
		}
	
	cout << a << '/' << b << endl;
	
	return 0;
}

