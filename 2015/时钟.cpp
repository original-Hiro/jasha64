#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a, b, c, d, Res, p;
	bool SP12h;
	
	cout << "Initial time  Final time  Passes" << endl;
	
	while (cin >> a >> b >> c >> d)
	{
		SP12h = false;
		printf("       %02d:%02d       %02d:%02d", a, b, c, d);
		
		Res = 0; p = (a * 5 + b / 12) % 60;
		while (a != c || b != d)
		{
			++b;
			if (b == 60) {a = (a + 1 == 12 ? 12 : (a + 1) % 12); b = 0; p = (p + 1) % 60;}
			else if (b % 12 == 0) p = (p + 1) % 60;
			if (p == b)
			{
				if (!SP12h || a != 12 || b) ++Res;
				else SP12h = false;
				if (a == 11 && b == 59) SP12h = true;
			}
		}
		
		printf("%8d\n", Res);
	}
	
	return 0;
}

