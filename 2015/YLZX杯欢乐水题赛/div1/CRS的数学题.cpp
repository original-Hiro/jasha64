#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 27, MOD = 0x7fffffff;
long long Std_Value[N], v[N];
string s;
istringstream ss;

struct State
{
	long long v, c1, c2;
	char c3;
	
	State() {}
	State(long long V, long long C1, long long C2, char C3) {v = V; c1 = C1; c2 = C2; c3 = C3;}
} C;
stack<State> st[N];
long long Pow(long long a, int b)
{
	long long c = 1;
	while (b)
	{
		if (b & 1) c = c * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return c;
}
void Calc()
{
	int i, c4;
	long long c1[N], c2[N] = {0};
	char c, c3[N];
	
	fill(c1, c1 + N, 1);
	fill(v, v + N, 0);
	fill(c3, c3 + N, '+');
	ss.str(s);
	while (ss >> c)
	{
		if (c == '^') ss >> c4;
		for (i = 0; i < N; ++i)
			switch (c)
			{
				case '(': 
					st[i].push(State(v[i], c1[i], c2[i], c3[i]));
					v[i] = c2[i] = 0; c1[i] = 1; c3[i] = '+';
					break;
				case ')':
					C = st[i].top(); st[i].pop();
					if (c3[i] == '+') c2[i] = (v[i] + c1[i] * c2[i] % MOD) % MOD;
					else c2[i] = (v[i] - c1[i] * c2[i] % MOD) % MOD;
					c1[i] = C.c1; c3[i] = C.c3; v[i] = C.v;
					break;
				case '+':
				case '-':
					if (c3[i] == '+') v[i] = (v[i] + c1[i] * c2[i] % MOD) % MOD;
					else v[i] = (v[i] - c1[i] * c2[i] % MOD) % MOD;
					c1[i] = 1; c2[i] = 0; c3[i] = c; break;
				case '*': c1[i] = c1[i] * c2[i] % MOD; c2[i] = 0; break;
				case '^': c2[i] = Pow(c2[i], c4); break;
				case 'a': c2[i] = i; break;
				default: c2[i] = c2[i] * 10 + c - '0';
			}
	}
	for (i = 0; i < N; ++i)
		if (c3[i] == '+') v[i] = (v[i] + c1[i] * c2[i] % MOD) % MOD;
		else v[i] = (v[i] - c1[i] * c2[i] % MOD) % MOD;
	ss.clear();
}

int main()
{
	int n, i, j;
	bool OK, Flag = false;
	
	getline(cin, s);
	Calc();
	copy(v, v + N, Std_Value);
	getline(cin, s);
	ss.str(s);
	ss >> n;
	ss.clear();
	for (i = 0; i < n; ++i)
	{
		getline(cin, s);
		Calc();
		OK = true;
		for (j = 0; j < N; ++j)
			if ((Std_Value[j] - v[j]) % MOD) {OK = false; break;}
		if (OK) {Flag = true; cout << (char)(i + 'A');}
	}
	if (!Flag) cout << ">w<";
	cout << endl;
	
	return 0;
}

