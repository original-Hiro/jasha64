#include <iostream>
using namespace std;

const int n = 10;
int use[n], rec[n];
int occ[n], fr[n], beg[n]; //occupied; free; begin

int main()
{
	for (int i = 0; i < n; i++) cin >> use[i] >> rec[i];
	for (int i = 0; i < n; i++) cin >> occ[i] >> fr[i] >> beg[i];

	long long tim = 0;
	for (int k = 0; k < 3; k++)
		for (int i = 0; i < n; i++)
		{
			if (tim >= beg[i])
			{
				int dt = (tim - beg[i]) % (occ[i] + fr[i]);
				if (dt < occ[i]) {tim += occ[i] - dt; dt = occ[i];}
				tim += use[i];
				if (use[i] + (dt-occ[i]) > fr[i]) beg[i] = tim;
			}
			else {
				tim += use[i];
				if (tim > beg[i]) beg[i] = tim;
			}
			tim += rec[i];
		}
	tim -= rec[n-1];

	cout << tim << endl;
	return 0;
}

