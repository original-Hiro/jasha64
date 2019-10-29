#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200007;
struct Range
{
    int s, t;
    friend bool operator < (const Range& a, const Range& b) {
	if (a.t != b.t) return a.t < b.t;
	return a.s < b.s;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].s >> a[i].t;

    sort(a, a+n);
    int p = a[0].t;
    vector<int> v;
    v.push_back(p);
    for (int i = 1; i < n; i++)
	if (a[i].s > p) v.push_back(p = a[i].t);
    
    cout << v.size() << endl << v[0];
    for (int i = 1; i < v.size(); i++) cout << ' ' << v[i];
    cout << endl;
    
    return 0;
}
