#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	
	cin >> s;
	int i; 
	for (i = 0; i < s.size(); i++)
		if (s[i] == '1') break;
	int Count = 0;
	for (i++; i < s.size(); i++)
		if (s[i] == '0') ++Count;
	
	if (Count >= 6) cout << "yes" << endl;
	else cout << "no" << endl;
	
	return 0;
}

