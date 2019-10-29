//POJ 2002 Squares
//unordered_set×ö·¨ 
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cstddef>
using namespace std;

typedef pair<int, int> pii;
pii pt[1001];
void Assign(pii p1, pii p2, pii& p3, pii& p4, int dx, int dy) //assign p3 = p1 + (dx, dy), p4 = p2 + (dx, dy) 
{
	p3.first = p1.first + dx; p3.second = p1.second + dy;
	p4.first = p2.first + dx; p4.second = p2.second + dy;
}
struct _2DHash
{
	size_t operator() (pii pt) const {return pt.first * 20001 + pt.second;}  
};

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n && n != 0)
	{
		unordered_set<pii, _2DHash> hash;
		for (int i = 0; i < n; i++) {cin >> pt[i].first >> pt[i].second; hash.insert(pt[i]);}
		
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
			{
				pii p1 = pt[i], p2 = pt[j], p3, p4;
				int dx = -(p2.second - p1.second), dy = p2.first - p1.first;
				Assign(p1, p2, p3, p4, dx, dy);
				if (hash.find(p3) != hash.end() && hash.find(p4) != hash.end()) res++;
				Assign(p1, p2, p3, p4, -dx, -dy);
				if (hash.find(p3) != hash.end() && hash.find(p4) != hash.end()) res++;
			}
		
		res /= 4;
		cout << res << endl;
	}
	
	return 0;
}

