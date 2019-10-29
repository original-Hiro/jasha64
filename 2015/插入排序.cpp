#include <iostream>
using namespace std;

const int N = 5007;
int a[N]; 

int main()
{
	int n;
	int i, j, d;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> d;
		for (j = i; j > 0; j--)
		{
			if (a[j - 1] > d) break;
			a[j] = a[j - 1];
		}
		a[j] = d;
	}
	
	cout << a[0];
	for (i = 1; i < n; i++) cout << ' ' << a[i];
	cout << endl;
	
	return 0;
}

