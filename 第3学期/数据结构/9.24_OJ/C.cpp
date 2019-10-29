#include <iostream>
#include <cstdlib>
using namespace std;

const int md[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int a;
	cin >> a;
	int m = a % 10000 / 100;
	int d = a % 100;
	
	int res = 0;
	while (m < 9) res += md[m++];
	while (m > 9) res -= md[--m];
	while (d < 17) {res++; d++;}
	while (d > 17) {res--; d--;}
	
	cout << abs(res) << endl;
	return 0;
}

