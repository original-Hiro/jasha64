#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		int Sum = 0, Min = 1e6;
		for (int i = 0, c; i < n; i++) {cin >> c; Sum += c; Min = min(Min, c);}
		if ((n % 2 && Sum % 2) || (n % 2 == 0 && (Sum % 2 || Min % 2))) cout << "Yalalov" << endl;
		else cout << "Shin" << endl;
	}
	
	return 0;
}

