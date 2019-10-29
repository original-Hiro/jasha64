#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 27, M = 26;
int EdgeN;
int InDegree[N], OutDegree[N], Father[N];

int Find(const int& x)
{
	if (Father[x] != x) Father[x] = Find(Father[x]);
	return Father[x];
}
bool Check()
{	
	int i, Count = 0;
	for (i = 1; i <= M; i++)
		if (InDegree[i] + OutDegree[i] && Father[i] == i) Count++;
	if (Count != 1) return false;
	
	int Odd = 0;
	for (i = 1; i <= M; i++)
		if (InDegree[i] + OutDegree[i])
		{
			if (InDegree[i] - OutDegree[i] < -1
			|| InDegree[i] - OutDegree[i] > 1) return false;
			if (InDegree[i] != OutDegree[i])
			{
				if (Odd < 2) Odd++;
				else return false;
			}
		}
	
	return true;
}

int main()
{
	int T;
	int i, c1, c2;
	char cache;
	
	cin >> T;
	while (T--)
	{
		fill(InDegree, InDegree + N, 0);
		fill(OutDegree, OutDegree + N, 0);
		for (i = 1; i <= M; i++) Father[i] = i;
		
		cin >> EdgeN;
		for (i = 0; i < EdgeN; i++)
		{
			scanf(" %c", &cache); c1 = cache - 'a' + 1;
			while (scanf("%c", &cache) && islower(cache)) c2 = cache - 'a' + 1;
			OutDegree[c1]++; InDegree[c2]++;
			c1 = Find(c1); c2 = Find(c2);
			Father[c1] = c2;
		}
		
//		for (i=1;i<=M;i++) cout<<Father[i]<<' '; cout<<endl;
		
		if (!Check()) cout << "The door cannot be opened." << endl;
		else cout << "Ordering is possible." << endl;
	}
	
	return 0;
}

