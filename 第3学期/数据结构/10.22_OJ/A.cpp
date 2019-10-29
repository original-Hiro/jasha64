#include <algorithm>
#include <stack>
#include <cstring>
#include <cstdio>
using namespace std;

char c[100001];
stack<char> s;

int main()
{
	int cnt['z'+1] = {};
	bool vis['z'+1];
	fill(vis + 'a', vis + 'z' + 1, 1);
	scanf("%s", c);
	int len = strlen(c);
	for (int i = 0; i < len; i++) {cnt[c[i]]++; vis[c[i]] = 0;}
	
	for (int i = 0; i < len; i++)
	{
		if (vis[c[i]]) {cnt[c[i]]--; continue;}
		while (!s.empty() && cnt[s.top()] && c[i] < s.top()) {vis[s.top()] = 0; s.pop();}
		s.push(c[i]);  cnt[c[i]]--; vis[c[i]] = 1;
	}
	
	stack<char> o;
	while (!s.empty()) {o.push(s.top()); s.pop();}
	while (!o.empty()) {putchar(o.top()); o.pop();}
	return 0;
}

