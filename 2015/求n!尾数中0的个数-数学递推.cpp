#include <iostream>
using namespace std;

const int 
a[] = {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125},
f[] = {1,  6,  31, 156,  781,  3906, 19531,  97656,  488281, 2441406, 12207031,  61035156,  305175781};

int main()
{
	int n;
	int i, Res = 0;
	
	cin >> n;
	
	while (n >= 5)
	{
		for (i = -1;; i++)
			if (n < a[i + 1]) break;
		Res += n / a[i] * f[i];
		n %= a[i];
	}
	
	cout << Res << endl;
	
	return 0;
}

