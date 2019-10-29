#include <iostream>
#include <deque>
using namespace std;

struct Data {int pos, val;};
deque<Data> dq;

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	long long res = 0;
	cin >> n >> k;
	for (int i = 0, d; i < n; i++)
	{
		if (!dq.empty() && dq.front().pos <= i-k) dq.pop_front();
		cin >> d;
		while (!dq.empty() && d >= dq.back().val) dq.pop_back();
		dq.push_back((Data){i, d});
		if (i >= k-1) res += dq.front().val;
	}
	cout << res << endl;
	return 0;
}

