#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int v = 0): data(v), next(NULL) {}
} *pre;
inline void fw(Node*& o) {o = o -> next;}
void Free(Node*& b, Node* e)
{
	while (b != e)
	{
		Node* c = b -> next;
		delete b; b = c;
	}
}

int main()
{
	pre = new Node();
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	if (n == 1) {int c; cin >> c; cout << c << endl; return 0;}
	Node* tmp = pre;
	while (n--)
	{
		int c;
		cin >> c;
		tmp -> next = new Node(c);
		fw(tmp);
	}
	
	Node *c1 = pre, *c2 = pre -> next, *c3 = pre -> next -> next;
	while (c3 != NULL)
	{
		if (c2 -> data != c3 -> data) {fw(c1); fw(c2); fw(c3);}
		else {
			while (c3 != NULL && c3 -> data == c2 -> data) fw(c3);
			c1 -> next = c3;
			Free(c2, c3);
			if (c3 != NULL) c3 = c3 -> next;
		}
	}
	
	tmp = pre -> next;
	if (tmp) {cout << tmp -> data; fw(tmp);}
	while (tmp) {cout << ' ' << tmp -> data; fw(tmp);}
	
	return 0;
}

