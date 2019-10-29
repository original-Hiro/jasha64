#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int k1, k2;
	int i;
	double a, b, c;
	string s;
	stringstream ss;
	
	cin >> a >> b >> k1 >> k2;
	
	c = a / b;
	
	ss << setiosflags(ios::fixed) << setprecision(k2) << c;
	ss >> s;
	
	for (i = 0; i < s.size(); i++)
		if (s[i] == '.') s = s.substr(i + 1);
		
	for (i = k1 - 1; i < k2; i++) cout << s[i];
	cout << endl;
	
	return 0;
}

