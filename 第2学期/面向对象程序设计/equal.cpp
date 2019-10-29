#include <iostream>
#include <algorithm>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
	string s;
	
	cin >> s;
	
	if (equal(s.begin(), s.end(), s.rbegin())) cout << 'Y' << endl;
	else cout << 'N' << endl;
	
	return 0;
}

