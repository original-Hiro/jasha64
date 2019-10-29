/*
因为这题需要我们求K代祖先，K是定值，所以不一定非要用倍增 
我们可以进行一次DFS，把到当前点之前的DFS序列存在栈中 
因为DFS序列中的节点一定是层次依次变深的，所以从栈顶往下数第k个即为所求 
*/
#include <iostream>
using namespace std;

const int N = 100001;
int fa[N], cnt[N], Left[N], Right[N];
inline void AddChild(int v, int u) {Right[u] = Left[v]; Left[v] = u;}
struct Stack
{
	int st[N], Top = 0;
	void push(int x) {st[Top++] = x;}
	void pop() {Top--;}
	int size() {return Top;}
	int kth(int k) {return st[Top - k];}
} st;
int k;
void DFS(int v)
{
	if (st.size() >= k) cnt[st.kth(k)]++;
	st.push(v);
	for (int u = Left[v]; u != 0; u = Right[u]) DFS(u);
	st.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    for (int v = 2; v <= n; v++) {cin >> fa[v]; AddChild(fa[v], v);}

    DFS(1);

    cout << cnt[1];
    for (int i = 2; i <= n; i++) cout << ' ' << cnt[i];
    cout << endl;
    return 0;
}

