#include <fstream>
#include <stack>
#include <utility>
#include <vector>
#include <cctype>
using namespace std;

ifstream cin("game.in");
ofstream cout("game.out");
typedef pair<int, int> pii;

const int N = 27, T = 4;
int n, arr[N];
char s[27] = {};
const char C[T] = {' ', 'B', 'C', 'A'};
int CC[127];
stack<char> Printer;
vector<pii> G[N][T];

bool Search(int p, int c)
{
	if (p == n+1) return true;
	for (int i = 0; i < G[p][c].size(); i++)
	{
		int tpos = G[p][c][i].first, typ = G[p][c][i].second;
		if (tpos < p && arr[tpos] != typ) return false;
	}
	arr[p] = c;
	for (int i = 0; i < G[p][c].size(); i++)
	{
		int tpos = G[p][c][i].first, typ = G[p][c][i].second;
		if (tpos > p) arr[tpos] = typ;
	}
	if (arr[p+1])
	{
		if (toupper(s[p+1]) != C[arr[p+1]] && Search(p+1, arr[p+1])) {Printer.push(C[c]); return true;}
		else {arr[p] = 0; return false;}
	}
	else {
		for (int i = 1; i < T; i++)
		{
			if (toupper(s[p+1]) == C[i]) continue;
			if (Search(p+1, i)) {Printer.push(C[c]); return true;}
		}
		arr[p] = 0; return false;
	}
}

int main()
{
	int d, m;
	
	CC['B'] = 1; CC['C'] = 2; CC['A'] = 3;
	
	cin >> n >> d;
	if (n > 20) {cout << -1 << endl; return 0;}
	cin >> (s+1);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, c;
		char b, d;
		cin >> a >> b >> c >> d;
		G[a][CC[b]].push_back(pii(c, CC[d]));
	}
	
	for (int i = 1; i < T; i++)
		if (Search(1, i)) break;
	if (Printer.empty()) cout << -1;
	else while (!Printer.empty()) {cout << Printer.top(); Printer.pop();}
	cout << endl;
	
	return 0;
}

