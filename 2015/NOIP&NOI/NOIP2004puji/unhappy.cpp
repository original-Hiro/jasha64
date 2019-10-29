#include <fstream>
using namespace std;

ifstream cin("unhappy.in");
ofstream cout("unhappy.out");

int main()
{
	int a, b, i, Day = 0, Unhappy = 0;
	
	for (i = 1; i <= 7; i++)
	{
		cin >> a >> b;
		
		if (a + b > 8)
			if (a + b - 8 > Unhappy)
			{
				Unhappy = a + b - 8;
				Day = i;
			}
	}
	
	cout << Day << endl;
	
	return 0;
}

