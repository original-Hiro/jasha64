#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int S = 100;
int h[902];

int main()
{
	int n, m, vol;
	int i, kase = 0;
	float level, rate;
	
	while ((cin >> m >> n) && m && n)
	{
		for (i = 1; i <= m * n; i++) cin >> h[i];
		cin >> vol;
		
		sort (h + 1, h + m * n + 1);
		for (i = 1; i <= m * n; i++)
		{
				vol -= S * i * (h[i + 1] - h[i]);
			if (vol < 0) break;
		}
		if (vol < 0)
		{
			vol += S * i * (h[i + 1] - h[i]);
			level = h[i] + (float) vol / (S * i);
			rate = (float) (vol? i: i - 1) / (m * n) * 100;
		}
		else {
			level = h[m * n] + (float) vol / (S * m * n);
			rate = 100.00;
		}
		
		cout << "Region " << ++kase << endl << "Water level is ";
		cout << setiosflags (ios :: fixed) << setprecision (2) << level;
		cout << " meters." << endl;
		cout << setiosflags (ios :: fixed) << setprecision (2) << rate;
		cout << " percent of the region is under water." << endl << endl;
	}
	
	return 0;
}

