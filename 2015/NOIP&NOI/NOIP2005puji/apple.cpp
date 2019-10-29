#include <fstream>
using namespace std;

ifstream cin("apple.in");
ofstream cout("apple.out");

int main()
{
	int h[17] = {0}, H;
	int i, Res = 0;
	
	for (i = 0; i < 10; i++) cin >> h[i];
	cin >> H;
	
	for (i = 0; i < 10; i++)
		if (H + 30 >= h[i]) Res++;
		
	cout << Res << endl;
	
	return 0;
}

