#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string s;

void Concatenate(int n)
{
	string cache;
	stringstream ss;
	for (int i = 1; i <= n; i++)
	{
		ss << i;
		ss >> cache;
		ss.clear();
		s += cache;
	}
}
long long Mod(int m)
{
	int i, Len = s.size();
	long long Res = 0;
	for (i = 0; i < Len; i++) Res = (Res * 10 + s[i] - '0') % m;
	return Res;
}

int main()
{
	long long n, m;
	
	cin >> n >> m;
	
	Concatenate(n);
	
	cout << Mod(m) << endl;
	
	return 0;
}

