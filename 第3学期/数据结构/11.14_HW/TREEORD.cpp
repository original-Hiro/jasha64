//SPOJ - tree order
//递归 
//因为根据前序遍历和中序遍历可以唯一确定二叉树的形态，所以我们从给定的前序遍历和 
//中序遍历恢复出二叉树，再检查这棵树的后序遍历是否与输入的后序遍历相同即可 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 8001;
struct Node
{
	int id;
	Node* left;
	Node* right;
	Node(int x = 0): id(x), left(NULL), right(NULL) {}
} *Root;
int pre[N], in[N], post1[N];
//建树的具体方法：因为前序遍历的第一个字符一定是根，我们在中序遍历中找出根所在的位置，
//它将中序遍历划分成两部分，左边一部分为左子树，右边一部分为右子树，左子树和右子树在 
//先序遍历中的长度和中序遍历中的长度是相等的，据此即可求出左右子树对应的先序、中序遍历 
//序列各是哪一段，递归进行即可 
//根据前序遍历序列[l1, r1)和中序遍历序列[l2, r2)建树 
Node* Build_Tree(int l1, int r1, int l2, int r2)
{
	if (l1 == r1) return NULL;
	Node* ret = new Node(pre[l1]);
	int pos = find(in + l2, in + r2, pre[l1]) - in, lslen = pos - l2;
	//左子树的根在中序遍历中对应的下标，左子树在先序和中序遍历中对应的长度 
	ret -> left = Build_Tree(l1 + 1, l1 + 1 + lslen, l2, pos);
	ret -> right = Build_Tree(l1 + 1 + lslen, r1, pos + 1, r2);
	return ret;
}
int post2[N], Top = 0;
void Post_Order(Node* o)
{
	if (o -> left != NULL) Post_Order(o -> left);
	if (o -> right != NULL) Post_Order(o -> right);
	post2[Top++] = o -> id;
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> pre[i];
	for (int i = 0; i < n; i++) cin >> post1[i];
	for (int i = 0; i < n; i++) cin >> in[i];
	
	Root = Build_Tree(0, n, 0, n);
	Post_Order(Root);
	cout << (memcmp(post1, post2, n * sizeof(int)) == 0 ? "yes" : "no") << endl;
	
	return 0;
}

