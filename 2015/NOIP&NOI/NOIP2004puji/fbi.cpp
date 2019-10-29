#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

ifstream cin("fbi.in");
ofstream cout("fbi.out");
string s;
int Len;
char f[1 << 12 | 1];

void Build()
{
	int i, x = s.size();
	for (i = x; i < x << 1; i++)
	{
		if (s[i - s.size()] == '1') f[i] = 'I';
		else f[i] = 'B';
	}
	fill(f + (s.size() << 1),
	f + (s.size() << 1) + s.size(), '\0');
	while (x > 0)
	{
		x >>= 1;
		for (i = x; i < x << 1; i++)
		{
			if (f[i << 1] == 'I' && f[i << 1 | 1] == 'I')
				f[i] = 'I';
			else
			if (f[i << 1] == 'B' && f[i << 1 | 1] == 'B')
				f[i] = 'B';
			else f[i] = 'F';
		}
	}
}
void Back_Order(const int& Root)
{
	if (f[Root << 1] != '\0') Back_Order(Root << 1);
	if (f[Root << 1 | 1] != '\0') Back_Order(Root << 1 | 1);
	cout << f[Root];
}

int main()
{
	cin >> Len;
	cin >> s;
	
	fill(f, f + (1 << 12 | 1), '\0');
	Build();
	
	Back_Order(1);
	cout << endl;
	
	return 0;
}

