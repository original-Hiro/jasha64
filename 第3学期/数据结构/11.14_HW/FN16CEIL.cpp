//SPOJ - ceiling function
//树的建立与同构判断 
//树的建立只需要按照题目所说暴力构建（复杂度O(k*k), k<=20, 不会超时） 
//树的同构，可以通过如下方法暴力判断：T1 == T2 当且仅当 T1和T2为空 或是 
//T1的左子树和T2的左子树同构并且T1的右子树和T2的右子树同构（复杂度也只有O(k)） 
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int val;
	Node* ch[2];
	Node(int x = 0): val(x), ch{} {}
};
bool EqualShape(Node* a, Node* b)
{
	if (a == NULL || b == NULL) return a == NULL && b == NULL;
	return EqualShape(a -> ch[0], b -> ch[0]) && EqualShape(a -> ch[1], b -> ch[1]);
}
inline Node* Newnode(int x) {return new Node(x);}
struct Tree
{
	Node* Root;
	Tree(int k = 0): Root(NULL)
	{
		for (int i = 0, cur; i < k; i++)
		{
			cin >> cur;
			if (Root == NULL) {Root = Newnode(cur); continue;}
			Node* o = Root;
			while (true)
			{
				int d = cur > o -> val ? 1 : 0;
				if (o -> ch[d] == NULL) {o -> ch[d] = Newnode(cur); break;}
				else o = o -> ch[d];
			}
		}
	}
	friend bool operator == (const Tree& a, const Tree& b) {return EqualShape(a.Root, b.Root);}
};
vector<Tree> Table;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		Table.clear();
		while (n--)
		{
			Tree T1(k);
			bool dup = 0;
			for (auto T2 : Table)
				if (T1 == T2) {dup = 1; break;}
			if (!dup) Table.push_back(T1);
			//本来准备用unordered_set完成判重，但是它对于自定义类型是没有默认哈希函数的 
			//也就是说要自己定义一个哈希函数，但是树的哈希过于复杂，遂放弃 
		}
		cout << Table.size() << endl;
	}
	return 0;
}
//参考资料：这道题下面的评论 
//又是一道查不到题解的题目，如果没有这个评论，我可能就要用其他奇怪的方法来判同构了 
//在此记录我的一个思路：把每个节点上的值离散化，则同一个位置上的节点的值一定相等，
//然后保存一棵树的前序和中序遍历结果， 因为根据前序和中序遍历可以唯一确定二叉树，
//所以判断两棵树是否同构只需要判断它们的 两种遍历结果是否相等即可
//（但比题解中给的方法复杂，遂选择了题解中给的方法） 

