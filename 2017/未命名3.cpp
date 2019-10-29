#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string s[3] = {"yp", "myj", "tym"};

int main()
{
	srand(19260817);
	
	int lim = rand() % 6;
	for (int i = 0; i < lim; i++) next_permutation(s, s + 3);
	cout << s[0] << endl;
	
	return 0;
}

