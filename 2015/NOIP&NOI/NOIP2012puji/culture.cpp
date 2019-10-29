#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

ifstream cin("culture.in");
ofstream cout("culture.out");
const int N = 107, M = 10007, INF = 10000007;
int CountryN, CultureN, RoadN, Start, To;
int Culture[N], RoadS[M], RoadT[M], RoadL[M];
int f[N];
bool Against[N][N];

struct Node
{
	int Point;
	bool Studied[N];
	
	Node() {Point = 0; fill(Studied + 1, Studied + CultureN + 1, 0);}
};

bool Available(const Node& a, const int& b)
{
	if (a.Studied[b]) return false;
	for (int i = 1; i <= CultureN; i++)
		if (Against[b][i] && a.Studied[i]) return false;
	return true;
}
void BFS()
{
	int i;
	Node node, cache;
	queue<Node> q;
	
	cache.Point = Start;
	cache.Studied[Culture[Start]] = 1;
	q.push(cache);
	fill(f + 1, f + Start, INF);
	fill(f + Start + 1, f + CountryN + 1, INF);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (i = 0; i < RoadN; i++)
		{
			if (RoadS[i] == node.Point && f[node.Point] + RoadL[i] <= f[RoadT[i]]
			&& Available(node, Culture[RoadT[i]]))
			{
				f[RoadT[i]] = f[node.Point] + RoadL[i];
				cache.Point = RoadT[i];
				copy(node.Studied + 1, node.Studied + CultureN + 1, cache.Studied + 1);
				cache.Studied[Culture[RoadT[i]]] = 1;
				q.push(cache);
			}
			if (RoadT[i] == node.Point && f[node.Point] + RoadL[i] <= f[RoadS[i]]
			&& Available(node, Culture[RoadS[i]]))
			{
				f[RoadS[i]] = f[node.Point] + RoadL[i];
				cache.Point = RoadS[i];
				copy(node.Studied + 1, node.Studied + CultureN + 1, cache.Studied + 1);
				cache.Studied[Culture[RoadS[i]]] = 1;
				q.push(cache);
			}
		}
	}
}

int main()
{
	int i, j;
	
	cin >> CountryN >> CultureN >> RoadN >> Start >> To;
	for (i = 1; i <= CountryN; i++) cin >> Culture[i];
	for (i = 1; i <= CultureN; i++)
		for (j = 1; j <= CultureN; j++) cin >> Against[i][j];
	for (i = 0; i < RoadN; i++) cin >> RoadS[i] >> RoadT[i] >> RoadL[i];
	
	BFS();
	
	if (f[To] == INF) cout << -1 << endl;
	else cout << f[To] << endl;
	
	return 0;
}

