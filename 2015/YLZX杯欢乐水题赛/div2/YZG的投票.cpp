#include <iostream>
using namespace std;

typedef long double LD;

int GCD(int a, int b)
{
	int c;
	while (b) {c = a % b; a = b; b = c;}
	return a;
}

int main()
{
	int A, B, L, a, b, i, j;
	LD NUM, num, cha = 1000000.0;
	
	cin >> A >> B >> L;
	
	NUM = (LD)A / (LD)B;
	for (i = 1; i <= L; ++i)
		for (j = 1; j <= L; ++j)
			if (GCD(i, j) == 1)
			{
				num = (LD)i / (LD)j;
				if (num >= NUM && num - NUM < cha)
				{
					a = i;
					b = j;
					cha = num - NUM;
				}
			}
		
	cout << a << ' ' << b << endl;
	
	return 0;
}

