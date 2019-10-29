#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define PRE t0 = s0.top(), s0.pop(), t1 = s1.top(), s1.pop(), s.pop()
#define CC s0.top() = ((s0.top() + s1.top()) * t0 + s0.top() * t1) % MOD, s1.top() = s1.top() * t1 % MOD
#define CJ s1.top() = ((s1.top() + s0.top()) * t1 + s1.top() * t0) % MOD, s0.top() = s0.top() * t0 % MOD

const int MOD = 10007;
stack<int> s0, s1;
stack<char> s;

int main()
{
	int i, n, t0, t1;
	char c = 0, c1 = '#';
	bool Done = false;
	
	cin >> n;
	while (c != '(' && c != ')' && c != '+' && c != '*') c = getchar();
	
	s0.push(1); s1.push(1);
	for (i = 1; i <= n; ++i)
	{
		if (c == '*')
		{
			if (!s.empty() && s.top() == '*') {PRE; CC;}
			s.push('*'); s0.push(1); s1.push(1);
		}
		else if (c == '+')
		{
			if (!s.empty() && s.top() == '*') {PRE; CC;}
			s.push('+'); s0.push(1); s1.push(1);
		}
		else if (c == '(') s.push('(');
		else do {
			if (s.top() == '(')
			{
				s.pop();
				if (!s.empty() && s.top() == '*') {PRE; CC;}
				break;
			}
			c1 = s.top(); PRE;
			if (c1 == '*') CC;
			else CJ;
		} while (true);
		c1 = c; c = getchar();
	}
	if (!s.empty() && s.top() == '*') {PRE; CC;}
	while (!s.empty()) {PRE; CJ;}
	
	cout << s0.top() << endl;
	
	return 0;
}

