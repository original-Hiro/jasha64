#include <fstream>
using namespace std;

ofstream cout("game10.out");

int main()
{
	int i, j;
	
	cout << 1 << endl << 999;
	i = 1; j = 1;
//	while (j < 499) cout << ' ' << i << ' ' << j++;
//	cout << ' ' << i++ << ' ' << j;
//	while (j > 1) cout << ' ' << i << ' ' << j--;
//	cout << ' ' << i++ << ' ' << j;
//	while (j < 999) cout << ' ' << i << ' ' << j++;
//	cout << ' ' << i-- << ' ' << j;
//	while (j > 501) cout << ' ' << i << ' ' << j--;
//	cout << ' ' << i-- << ' ' << j;
	while (j < 999) cout << ' ' << i << ' ' << j++;
	cout << ' ' << i << ' ' << j << endl;
	
	return 0;
}

