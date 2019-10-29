#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0, c; i < n; i++) {cin >> c; pq.push(c);}
    for (int i = 0, c; i < m; i++)
    {
        if (i > 0) cout << ' ';
        cout << pq.top(); pq.pop();
        cin >> c; pq.push(c);
    }
    cout << endl;
    return 0;
}

