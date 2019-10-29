#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int kase;
    cin >> kase;
    while (kase--)
    {
		int l, s;
		cin >> l >> s;
		if (l % 2 == 0 && s % 2 != 0) {cout << -1 << endl; continue;}
		if (s > 9*l) {cout << -1 << endl; continue;}
		if (s == 1)
		{
		    if (l == 1) cout << 1 << endl;
		    else cout << -1 << endl;
		    continue;
		}
		
		int hl = l / 2, hs = s / 2; //half length & half sum
		if (hs > hl*9)
		{
		    for (int i = 0; i < hl; i++) putchar('9');
		    cout << s - (l-1) * 9;
		    for (int i = 0; i < hl; i++) putchar('9');
		    cout << endl;
		    continue;
		}
		queue<int> q; //printer for first half
		for (int i = 0; i < hl; i++)
		{
		    if (hs > 9) {hs -= 9; q.push(9);}
		    else if (hs > 0) {q.push(hs); hs = 0;}
		    else q.push(0);
		}
		
		stack<int> st; //printer for second half
		while (!q.empty())
		{
		    int v = q.front(); q.pop();
		    putchar(v + '0'); st.push(v);
		}
		if (l % 2 != 0) putchar(s % 2 + '0');
		while (!st.empty())
		{
		    int v = st.top(); st.pop();
		    putchar(v + '0');
		}
		cout << endl;
    }
    
    return 0;
}

