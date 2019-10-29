//SPOJ - word counting 2
//堆 
//一般的堆不支持修改元素这种操作，所以我们采取和Dijkstra算法相似的方式来规避： 
//每次改动时不处理改动前的元素，每次取出堆顶时判断这个元素是不是已过期，如果是，则丢弃这个元素 
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct HeapNode
{
	string str;
	int cnt;
	HeapNode(string s = "", int c = 0): str(s), cnt(c) {}
	friend bool operator < (const HeapNode& a, const HeapNode& b) //注意，默认是大根堆 
	{
		if (a.cnt != b.cnt) return a.cnt < b.cnt;
		return a.str > b.str;
	}
};
unordered_map<string, int> mp;
queue<string> q;
priority_queue<HeapNode> pq;

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		mp.clear();
		while (!pq.empty()) pq.pop();
		while (!q.empty()) q.pop();
		cout << "Case " << kase << ':' << endl;
		int n, k;
		cin >> n >> k;
		while (n--)
		{
			string s;
			cin >> s;
			if (q.size() == k)
			{
				string c = q.front(); q.pop();
				mp[c]--; pq.push(HeapNode(c, mp[c]));
			}
			q.push(s);
			if (mp.find(s) == mp.end()) mp[s] = 1;
			else mp[s]++;
			pq.push(HeapNode(s, mp[s]));
			while (mp[pq.top().str] != pq.top().cnt) pq.pop(); //丢弃所有过期元素 
			cout << pq.top().str << ' ' << pq.top().cnt << endl;
		}
	}
	
	return 0;
}
//最后再说句闲话，听说<algorithm>头文件里原生支持make_heap(), push_heap(), pop_heap(), heap_sort() 
//等堆的操作，但是它不支持修改，要想实现修改元素还是只能用pb_ds 

