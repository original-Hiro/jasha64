#include <iostream>
#include <map>
using namespace std;

map<string, string> m;

int main()
{
	int kase = 0;
	string s1, s2;
	
	m["A#"] = "Bb"; m["Bb"] = "A#";
	m["C#"] = "Db"; m["Db"] = "C#";
	m["D#"] = "Eb"; m["Eb"] = "D#";
	m["F#"] = "Gb"; m["Gb"] = "F#";
	m["G#"] = "Ab"; m["Ab"] = "G#";
	
	ios::sync_with_stdio(false);
	while (cin >> s1 >> s2)
	{
		cout << "Case " << ++kase << ": ";
		if (m.find(s1) == m.end()) cout << "UNIQUE" << endl;
		else cout << m[s1] << ' ' << s2 << endl;
	}
	
	return 0;
}

