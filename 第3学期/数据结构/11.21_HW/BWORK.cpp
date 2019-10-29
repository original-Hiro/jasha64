//SPOJ - boring homework
//模拟 
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//二叉树的节点 
extern struct Node* const null; //用"extern"关键字把虚拟null节点的声明提到类声明的前面, 这样在默认构造函数中即可用上null 
struct Node
{
	int val;
	int siz, l, r; //子树的大小，左子树的大小，右子树的大小 
	int ll, lr, rl, rr; //左子树的左子树的大小, 左子树的右子树的大小, 依此类推(画图用) 
	Node* ch[2];
	Node(int val = 0, int siz = 1): val(val), siz(siz), l(0), r(0), ll(0), lr(0), rl(0), rr(0), ch{null, null}
	{
		//cout << "Construction function called, val = " << val << ", siz = " << siz << endl;
		//带参数列表时构造函数的参数与结构体的参数允许重名，此时函数体内用这个名字指代的是函数参数而非结构体参数 
	}
	void Maintain()
	{
		ll = ch[0] -> l; lr = ch[0] -> r;
		rl = ch[1] -> l; rr = ch[1] -> r;
		l = ch[0] -> siz; r = ch[1] -> siz; siz = l + r + 1;
	}
} *Root;
Node* const null = new Node(0, 0); 

inline Node* Newnode(int v) {return new Node(v);}
//curh表示当前递归深度，递归过程中维护；h表示树的最大深度，输出答案时用 
int curh, h; //把当前深度和最大深度作为全局变量，这样在Insert过程中就不必反复传参 
void Insert(Node*& o, int val)
{
	h = max(h, curh);
	if (o == null) {o = Newnode(val); return;}
	//题目保证不会出现val == o->val的情况，故此处不予考虑 
	int d = o -> val > val ? 0 : 1;
	++curh; Insert(o -> ch[d], val); --curh;
	o -> Maintain();
}
//把地址pos起的n个字符全部赋值为c 
inline void Print(char* pos, int n, char c) {for (int i = 0; i < n; i++) pos[i] = c;}

//我们一般访问二叉树是按照DFS序，但是这样造成一个问题：一行的输出结果不是一次得出的 
//为了能够多次修改输出内容，我们选择把输出内容暂存到二维字符序列中，而且这样也方便最后输出时去除行末多余空格 
//当然，按照BFS序访问二叉树，将会允许一次完成一行的输出，从而就可以直接输出了。代码类似，此处从略。 
const int W = 158;
char out[159][W]; //因为每次递归调用可能访问到out的任何一个位置，所以声明成全局变量 
//说句闲话，这个数组一开始开的是159*79，但是WA，把宽改成原来的两倍以后就AC了 
//虽然不知道为什么宽度可能达到N的二倍，但是这启示我们，数组开小了也可能造成WA 

//以(row, col)为左上角，画出以o为根的子树 
void DrawTree(Node* o, int row, int col)
{
	if (o == null) return;
	
	//画出当前节点，画出分岔点正下方的竖线（如果有） 
	int lb = col, lp = col + o->ll, mid = col + o->l, rp = col + o->l + 1 + o->rl;
		//左边界所在列，左分岔点所在列，根节点所在列，右分岔点所在列 
	if (o -> ch[0] != null)
	{
		Print(&out[row][lb], o -> ll, ' '); Print(&out[row+1][lb], o -> ll, ' ');
		out[row][lp] = '+'; out[row+1][lp] = '|';
		Print(&out[row][lp+1], o -> lr, '-'); Print(&out[row+1][lp+1], o -> ll, ' ');
	}
	out[row][mid] = 'o';
	if (o -> ch[1] != null)
	{
		Print(&out[row][mid+1], o -> rl, '-'); Print(&out[row+1][mid+1], o -> ll, ' ');
		out[row][rp] = '+'; out[row+1][rp] = '|';
		Print(&out[row][rp+1], o -> rr, ' '); Print(&out[row+1][rp+1], o -> rr, ' ');
	}
	
	//递归画出子树 
	if (o -> ch[0] != null) DrawTree(o -> ch[0], row + 2, lb);
	if (o -> ch[1] != null) DrawTree(o -> ch[1], row + 2, mid + 1);
}

void RemoveTree(Node* o)
{
	if (o == null) return;
	RemoveTree(o -> ch[0]); RemoveTree(o -> ch[1]); delete o;
}

int main()
{
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		Root = null; h = 0;
		int n;
		cin >> n;
		for (int i = 0, c; i < n; i++) {cin >> c; Insert(Root, c);}
		h = 2 * h + 1; //图的最大高度等于树的最大深度的二倍+1（从0开始编号） 
		
		printf("Case #%d:\n", kase);
		fill(out[0], out[0] + h*W, ' ');
		DrawTree(Root, 0, 0);
		//去除行末多余空格 
		for (int i = 0; i < h; i++)
			for (int j = W-1; j >= 0; j--)
				if (out[i][j] == ' ') out[i][j] = 0;
				else break;
		for (int i = 0; i < h; i++) printf("%s\n", out[i]);
		
		RemoveTree(Root);
	}
	
	return 0;
}

