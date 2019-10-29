#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string s1, s2;
void Solve()
{
	for (int i = 0; i < s1.size(); i++) s1[i] = tolower(s1[i]);
	for (int i = 0; i < s2.size(); i++) s2[i] = tolower(s2[i]);
	
	s1 = ' ' + s1 + ' '; s2 = ' ' + s2 + ' ';
	int pos = -1, cnt = 0;
	int i = 0;
	while (i != -1)
	{
		i = s2.find(s1, i);
		if (i == -1) break;
		if (pos == -1) pos = i;
		cnt++; i++;
	}
	
	if (pos == -1) cout << -1 << endl;
	else cout << cnt << ' ' << pos << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	
	getline(cin, s1);
	getline(cin, s2);
	
	Solve();
	
	return 0;
}

