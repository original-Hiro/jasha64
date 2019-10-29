#include <iostream>
#include <map>
#include <iterator>
using namespace std;

string Name, a, b;
map<string, int> m;

int main()
{
	ios::sync_with_stdio(false);
	cin >> Name;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> a;
		for (int i = 0; i < 4; i++) cin >> b;
		if (a == Name)
			if (m.find(b) != m.end()) m[b]++;
			else m[b] = 1; 
		else if (b == Name)
			if (m.find(a) != m.end()) m[a]++;
			else m[a] = 1;
	}
	
	string res;
	int tim = 0;
	for (map<string, int>::iterator I = m.begin(); I != m.end(); I++)
		if (I -> second > tim) {tim = I -> second; res = I -> first;}
	if (tim == 0) cout << "DuiYouNe!" << endl;
	else cout << res << endl;
	
	return 0;
}

