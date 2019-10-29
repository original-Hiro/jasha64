#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
ofstream cout("1014.in");

int main()
{
	srand(time(0));
	int n = rand() % 6 + 1;
	cout << n << endl;
	for (int i = 0; i < n; i++) cout << rand() % 3 + 1 << endl;
	for (int i = 0; i < n; i++) cout << rand() % 3 + 1 << endl;
	
	return 0;
}

