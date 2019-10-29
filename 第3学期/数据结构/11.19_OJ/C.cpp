/*
这题有个巧妙的办法就是时间反演，这样就把"最晚"变成了"最早"。
我们把输入数据倒过来处理，每次从操作点开始逐步上跳并更新标记，遇到已标记点即停止。时间复杂度O(n)。 
*/
#include <iostream>
using namespace std;

const int N = 100001;
int fa[N], sgn[N], op[N];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int v = 2; v <= n; v++) cin >> fa[v];
    for (int i = 1; i <= n; i++) cin >> op[i];
    for (int i = n; i >= 1; i--)
		for (int v = op[i]; v != 0 && sgn[v] == 0; v = fa[v]) sgn[v] = op[i];
	
    if (n >= 2) cout << sgn[2];
    for (int v = 3; v <= n; v++) cout << ' ' << sgn[v];
    cout << endl;
    return 0;
}

