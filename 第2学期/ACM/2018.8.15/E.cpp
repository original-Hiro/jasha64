#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N = 100001;
int mk[N];
int Head[N], Next[N+N], t[N+N], w[N+N], id[N+N], Top = 2;
//v = 0 indicates par, v = 1 indicates perp
inline void AddEdge(int a, int b, int c, int d)
{
    t[Top] = b; w[Top] = c; id[Top] = d;
    Next[Top] = Head[a]; Head[a] = Top++;
}
queue<int> Printer;
bool vis[N+N];
bool use[N];
bool DFS(int u)
{
    use[u] = 1;
    for (int i = Head[u]; i; i = Next[i]) {
	int v = t[i];
	if (mk[v] == -1) {
	    mk[v] = mk[u] ^ w[i];
	    vis[i] = vis[i^1] = 1;
	    if (!DFS(v)) return false;
	}
	else if (mk[v] != mk[u] ^ w[i]) return false;
	else if (!vis[i]) {Printer.push(id[i]); vis[i] = vis[i^1] = 1;}
    }
    return true;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(mk, -1, sizeof(mk));
    char op[5];
    for (int i = 1, a, b; i <= m; i++) {
	scanf("%s", op);
	if (op[0] == 'h' || op[0] == 'v') {
	    int id = op[0] == 'h' ? 0 : 1;
	    scanf("%d", &a);
	    if (mk[a] == -1) mk[a] = id;
	    else if (mk[a] == id) Printer.push(i);
	    else {puts("inconsistent"); return 0;}
	}
	else {
	    scanf("%d%d", &a, &b);
	    int id = op[1] == 'a' ? 0 : 1;
	    AddEdge(a, b, id, i); AddEdge(b, a, id, i);
	}
    }

    for (int i = 1; i <= n; i++)
	if (!use[i] && mk[i] != -1 && !DFS(i)) {
	    puts("inconsistent"); return 0;
	}
    for (int i = 1; i <= n; i++)
	if (!use[i]) {
	    mk[i] = 0;
	    if (!DFS(i)) {puts("inconsistent"); return 0;}
	}

    puts("consistent");
    printf("%lu\n", Printer.size());
    if (!Printer.empty()) {printf("%d", Printer.front()); Printer.pop();}
    while (!Printer.empty()) {printf(" %d", Printer.front()); Printer.pop();}
    puts("");
    
    return 0;
}

