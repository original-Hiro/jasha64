#include <iostream>
using namespace std;

int N;
int Pow(int n, int k)
{
	if (k == 1) return n;
	int c = Pow(n, k/2) % N;
	if (k % 2) return (c*c % N)*n % N;
	else return c*c % N;
}

int main()
{
	int m, k, x;
	
	cin >> N >> m >> k >> x;
	
	cout << (x + m * Pow(10, k)) % N << endl;
	
	return 0;
}

