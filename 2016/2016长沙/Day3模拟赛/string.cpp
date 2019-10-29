#include <fstream>
#include <string>
#include <set>
using namespace std;

ifstream cin("string.in");
ofstream cout("string.out");
const int N = 6007;
string s[37], a[N];
set<string> vis;

int main()
{
	int n, Top = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		int len = s[i].size();
		for (int j = 1; j <= len; j++) a[Top++] = s[i].substr(0, j);
	}
	
	int Res = 0;
	for (int i = 0; i < Top; i++)
		for (int j = 0; j < Top; j++)
			if (!vis.count(a[i] + a[j])) {vis.insert(a[i] + a[j]); ++Res;}
	cout << Res << endl;
	
	return 0;
}

