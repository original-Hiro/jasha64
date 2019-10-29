#include <fstream>
using namespace std;

ifstream cin("save.in");
ofstream cout("save.out");
const int A = 300, B = 100;

int main()
{
	int cache;
	int i, save = 0, remaining = 0;
	
	for (i = 1; i <= 12; i++)
	{
		cin >> cache;
		if (remaining + A - cache < 0)
		{
			cout << -i << endl;
			return 0;
		}
		remaining += A - cache;
		while (remaining >= B)
		{
			remaining -= B;
			save += B;
		}
	}
	
	cout << save * 1.2 + remaining << endl;
	
	return 0;
}
 
