#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

struct building
{
	double x, width, y, depth, height;
	int num;
	bool visible;
	
	building () {x = width = y = depth = height = num = visible = 0;}
	bool inside (const double& site) {return x <= site && site <= x + width;}
	
	friend bool operator < (const building& a, const building& b)
	{
		if (a.x != b.x) return a.x < b.x;
		else return a.y < b.y;
	}
	friend istream& operator >> (istream& cin, building& a)
	{
		cin >> a.x >> a.y >> a.width >> a.depth >> a.height;
		return cin;
	}
} city[105];

set<double> pos;
set<double>::iterator I;

int main()
{
	int n;
	int kase(0), i, j;
	double cur_pos;
	
	while ((cin >> n) && n)
	{
		for (i = 1; i <= n; i++)
		{
			cin >> city[i];
			city[i].num = i;
		}
		
		sort (city + 1, city + n + 1);
		for (i = 1; i <= n; i++)
		{
			pos.insert (city[i].x);
			pos.insert (city[i].x + city[i].width);
		}
		for (i = 2; i <= n; i++)
		{
			if (city[i].visible) continue;
			I = pos.begin();
			while (1)
			{
				cur_pos = *I;
				I++;
				if (I == pos.end()) break;
				cur_pos += *I;
				cur_pos /= 2;
				if (!city[i].inside (cur_pos)) continue;
				for (j = 1; j <= n; j++)
				{
					if (!city[j].inside (cur_pos)) continue;
					if (city[j].y < city[i].y && city[j].height >= city[i].height) break;
				}
				if (j == n + 1) {city[i].visible = 1; break;}
			}
		}
		
		if (kase) cout << endl;
		cout << "For map #" << ++kase;
		cout << ", the visible buildings are numbered as follows:" << endl << city[1].num;
		for (i = 2; i <= n; i++) if (city[i].visible) cout << ' ' << city[i].num;
		cout << endl;
		
		fill (city + 1, city + n + 1, building () );
	}

	return 0;
}

