//SPOJ - word counting 2
//pbds解法 
//pb_ds(Policy-Based Data Structures)，黑科技般的库，比STL里的同种数据结构更快，功能也更多 
//此处我们利用pb_ds的优先队列支持修改元素和删除非最值元素的功能来完成该题，就避免了手写堆 
#include <iostream>
#include <queue>
#include <unordered_map>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

int id;
unordered_map<string, int> mp;
//unordered_map: 它的键不排序，直接将哈希结果组织成桶，来储存内容 
//随机访问快于map，顺序迭代慢于map 
//看似无序，但因为采用了哈希，它的find仍然是能在常数时间内完成的 
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
__gnu_pbds::priority_queue<HeapNode> pq;
__gnu_pbds::priority_queue<HeapNode>::point_iterator pos[100001];
//值得一提的是，本来我写了这样两行using语句： 
//using namespace std;
//using __gnu_pbds::priority_queue;
//结果在声明priority_queue的时候编译报错：ambiguous reference to "priority_queue" 
//显然这是<queue>头文件的STL的std::priority_queue与pb_ds库的priority_queue打架造成的 
//这反映了using namespace std;这一语句潜在的问题（其实在很多工程化开发中是忌用 
//这一语句的，但是平时的算法题目程序很短所以无伤大雅） 
queue<string> q;
void Insert(const string& str)
{
	if (mp.find(str) != mp.end())
	{
		int cur_id = mp[str], ncnt = pos[cur_id]->cnt + 1;
		pq.modify(pos[cur_id], HeapNode(str, ncnt));
	}
	else pos[mp[str] = id++] = pq.push(HeapNode(str, 1));
}
void Delete(const string& str)
{
	int cur_id = mp[str], ncnt = pos[cur_id]->cnt - 1;
	pq.modify(pos[cur_id], HeapNode(str, ncnt));
}
void Query()
{
	cout << pq.top().str << ' ' << pq.top().cnt << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		cout << "Case " << kase << ':' << endl;
		mp.clear(); pq.clear(); id = 0;
		while (!q.empty()) q.pop();
		//一开始WA了几发，后来发现q和pq忘记每笔测资之前初始化了
		//多笔测资的题目尤其要注意每笔测资前的初始化 
		//说句闲话，pb_ds的队列有clear操作，STL的队列只能while () pop();，后者实在太蠢了 
		int n, k;
		cin >> n >> k;
		while (n--)
		{
			string s;
			cin >> s;
			if (q.size() == k) {Delete(q.front()); q.pop();}
			Insert(s); q.push(s);
			Query();
		}
	}
	return 0;
}
//最后再说句闲话，听说<algorithm>头文件里原生支持make_heap(), push_heap(), pop_heap(), heap_sort() 
//等堆的操作，但是它不支持修改，所以我们还是只能用pb_ds 

