#include <iostream>
#include <deque>
#include <string>
using namespace std;

deque<int> dq;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		char op = s[1];
		char dir = op == 'o' ? s[4] : s[5];
		if (op == 'o')
		{
			if (dir == 'b' && !dq.empty()) dq.pop_back();
			if (dir == 'f' && !dq.empty()) dq.pop_front();
		}
		else {
			int x;
			cin >> x;
			if (dir == 'b') dq.push_back(x);
			else dq.push_front(x);
		}
	}
	
	bool fir = 1;
	do {
		if (fir) fir = 0;
		else cout << ' ';
		cout << dq.front(); dq.pop_front();
	} while (!dq.empty());
	cout << endl;
	
	return 0;
}

