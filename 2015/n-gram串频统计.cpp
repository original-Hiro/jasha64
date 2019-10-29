#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iterator>
using namespace std;

map<string, int> ms;

int main()
{
	int n, i, Max = 1, len;
	string s, s1;
	set<string>::iterator I;
	
	cin >> n >> s;
	len = s.size() - n;
	for (i = 0; i <= len; ++i)
	{
		s1 = s.substr(i, n);
		if (ms.count(s1)) Max = max(Max, ++ms[s1]);
		else ms[s1] = 1;
	}
	if (Max > 1)
	{
		cout << Max << endl;
		for (i = 0; i <= len; ++i)
			if (ms[s1 = s.substr(i, n)] == Max) {cout << s1 << endl; --ms[s1];}
	}
	else cout << "NO" << endl;
	
	return 0;
}

