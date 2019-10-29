#include <iostream>
#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

inline int Read()
{
	int r = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {r = r * 10 + c - '0'; c = getchar();}
	return r;
}
const int N = 4000001;
long long a[N];
stack<long long> s;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) a[i] = Read();
	
	for (int i = n-1; i >= 0; i--)
	{
		int cur = a[i];
		while (!s.empty() && s.top() == cur) {s.pop(); cur++;}
		s.push(cur);
	}
	
	bool ofs = s.size() > 1;
	while (s.size() > 1) s.pop();
	cout << s.top() + ofs << endl;
	return 0;
}

