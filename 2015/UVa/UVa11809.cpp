#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

const int E[31] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191,
16383, 32767, 65535, 131071, 262143, 524287, 1048575, 2097151, 4194303, 8388607,
16777215, 33554431, 67108863, 134217727, 268435455, 536870911, 1073741823};
const double LOGM[10] = {log10(0.5), log10(0.75), log10(0.875), log10(0.9375),
log10(0.96875), log10(0.984375), log10(0.9921875), log10(0.99609375),
log10(0.998046875), log10(0.9990234375)}, lg2 = log10(2);

int main()
{
	int i, j, m, e, pos;
	double a;
	double c, c1, c2, C;
	string s;
	istringstream ss;
	
	while ((cin >> s) && s != "0e0")
	{
		pos = s.find('e');
		ss.str(s.substr(0,pos - 1));
		ss >> c1;
		ss.clear();
		ss.str(s.substr(pos + 1));
		ss >> c2;
		ss.clear();
		
		C = log10(c1) + c2;
		m = 0;
		e = 1;
		c = fabs(C - LOGM[0] - E[1] * lg2);
		
		for (i = 0; i < 10; i++)
			for (j = 1; j <= 30; j++)
				if (fabs(C - LOGM[i] - E[j] * lg2) < c)
				{
					m = i;
					e = j;
					c = fabs(C - LOGM[m] - E[e] * lg2);
				}
		
		cout << m << ' ' << e << endl;
	}
	
	return 0; 
}

