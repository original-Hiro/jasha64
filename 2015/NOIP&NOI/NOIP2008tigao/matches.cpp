#include <fstream>
using namespace std;

ifstream cin("matches.in");
ofstream cout("matches.out");
int matches[2222] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	int n;
	int i, j, res = 0;
	
	cin >> n;
	
	for (i = 10; i <= 2222; i++) matches[i] = matches[i / 10] + matches[i % 10];
	
	for (i = 0; i <= 1111; i++)
		for (j = 0; j <= 1111; j++)
			if (matches[i] + matches[j] + matches[i + j] + 4 == n) res++;
	
	cout << res << endl;
	
	return 0;
}

