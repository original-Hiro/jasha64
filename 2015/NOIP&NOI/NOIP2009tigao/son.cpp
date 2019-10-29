#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

const int N = 50007;
int Prime[N], Top;
bool isp[N];

int main()
{
	int i, j;
	fill(isp + 2, isp + N, true);
	for (i = 2; i < N; ++i)
		if (isp[i])
		{
			for (j = i << 1; j < N; j += i) isp[j] = false;
			Prime[Top++] = i;
		}
	
	int T;
	cin >> T;
	while (T--)
	{
		int a[17] = {}, p[17] = {}, Top1 = 0, A0, pa0, A1, pa1, B0, pb0, B1, Res = 1;
		
		cin >> A0 >> A1 >> B0 >> B1;
		for (i = 0; i < Top; ++i)
			if (B1 % Prime[i] == 0)
			{
				a[Top1] = Prime[i];
				while (B1 % Prime[i] == 0) {++p[Top1]; B1 /= Prime[i];}
				++Top1;
			}
		if (B1 > 1) {a[Top1] = B1; p[Top1++] = 1;}
		
		for (i = 0; i < Top1; ++i)
		{
			pa0 = pa1 = pb0 = 0;
			while (A0 % a[i] == 0) {++pa0; A0 /= a[i];}
			while (A1 % a[i] == 0) {++pa1; A1 /= a[i];}
			while (B0 % a[i] == 0) {++pb0; B0 /= a[i];}
			if (pa0 == pa1 && pb0 == p[i]) Res *= pb0 - pa0 + 1;
			if (pa1 > p[i] || (pa0 > pa1 && pb0 < p[i] && pa1 != p[i])) {Res = 0; break;}
		}
		
		cout << Res << endl;
	}
	
	return 0;
}

