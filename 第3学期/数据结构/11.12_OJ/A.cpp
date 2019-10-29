#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <set>
using namespace std;

typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll> > pq;
set<ll> tb; //table
inline void Insert(ll x)
{
    if (tb.find(x) != tb.end()) return;
    pq.push(x); tb.insert(x);
}

int main()
{
    pq.push(1); tb.insert(1);
    int n;
    cin >> n;
    while (--n)
    {
        ll cur = pq.top(); pq.pop(); tb.erase(cur);
        Insert(cur*2); Insert(cur*3); Insert(cur*5);
    }
    cout << pq.top() << endl;
    return 0;
}

