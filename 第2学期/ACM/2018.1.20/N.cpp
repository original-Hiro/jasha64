#include <iostream>
#include <map> 
#include <string>
using namespace std;

map<string, int> m;

int main()
{
	m["I"] = 1; m["II"] = 2; m["III"] = 3;
	m["IV"] = 4; m["V"] = 5; m["VI"] = 6; m["VII"] = 7; m["VIII"] = 8;
	m["IX"] = 9; m["X"] = 10; m["XI"] = 11; m["XII"] = 12;
	
	string s;
	int kase = 0;
	
	ios::sync_with_stdio(false);
	while (cin >> s) cout << "Case " << ++kase << ": " << m[s] << endl;
	
	return 0;
}

