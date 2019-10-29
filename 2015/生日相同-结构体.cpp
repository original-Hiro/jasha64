#include <iostream>
#include <queue>
using namespace std;

struct People
{
	int Month, Day;
	string Name;
	
	friend bool operator < (const People& a, const People& b)
	{
		if (a.Month != b.Month) return a.Month > b.Month;
		if (a.Day != b.Day) return a.Day > b.Day;
		if (a.Name.size() != b.Name.size()) return a.Name.size() > b.Name.size();
		return a.Name > b.Name;
	}
} c;
priority_queue<People> pq;

int main()
{
	int n, i, m, d;
	bool Flag = false, Output = false;
	
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> c.Name >> c.Month >> c.Day;
		pq.push(c);
	}
	
	for (i = 0; i < n - 1; i++)
	{
		c = pq.top(); pq.pop();
		if (Output)
			if (c.Month == m && c.Day == d) cout << ' ' << c.Name;
			else {Output = false; cout << endl;}
		if (!Output && c.Month == pq.top().Month && c.Day == pq.top().Day)
		{
			m = c.Month; d = c.Day;
			cout << m << ' ' << d << ' ' << c.Name;
			Output = Flag = true;
		}
	}
	if (Output) cout << ' ' << pq.top().Name;
	
	if (!Flag) cout << "None" << endl;
	
	return 0;
}

