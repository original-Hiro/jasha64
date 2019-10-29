#include <iostream>
#include <cstdio>
#include <set>
#include <iterator>
using namespace std;

set<int> s;
set<int>::iterator I;

int main()
{
	int n, i, c;
	
	cin >> n;
	for (i = 0; i < n; ++i) {scanf("%d", &c); s.insert(c);}
	
	cout << *s.begin();
	for (I = s.begin(), ++I; I != s.end(); ++I) printf(" %d", *I);
	cout << endl;
	
	return 0;
}

