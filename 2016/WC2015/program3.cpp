#include <fstream>
using namespace std;

ifstream cin("program3.in");
ofstream cout("program3.out");
unsigned long long s1, s2, s3, s4, i, n;

int main()
{
	cin >> n;
	s1 = n * (n + 1) / 2;
	s2 = n * (n + 1) * (2 * n + 1) / 6;
	s3 = s1 * s1;
	s4 = (6 * n * n * n * n * n + 15 * n * n * n * n + 10 * n * n * n - n) / 30;
	cout << n + 1 << endl << n + 1 << endl;
	cout << s1 << endl << s1 << endl;
	cout << s2 << endl << s2 << endl;
	cout << s3 << endl << s3 << endl;
	cout << s4 << endl << s4 << endl;
	return 0;
}

