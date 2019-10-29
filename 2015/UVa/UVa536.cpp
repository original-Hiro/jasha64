#include <iostream>
#include <string> 
using namespace std;

struct Node
{
	char Data;
	Node *Left, *Right;
} *Root;
string s1, s2;

inline Node* newnode() {return new Node();} 
void Recover(int Left2, int Right2, int Left1, Node* Root)
{
	Root -> Data = s1[Left1];
	if (Left2 == Right2) return;
	int Pos = s2.find(s1[Left1]);
	if (Pos - 1 >= Left2) Recover(Left2, Pos - 1, Left1 + 1, Root -> Left = newnode());
	if (Pos + 1 <= Right2) Recover(Pos + 1, Right2, Left1 + Pos - Left2 + 1, Root -> Right = newnode());
}
void Post_Order(Node* Root)
{
	if (Root == NULL) return; 
	Post_Order(Root -> Left);
	Post_Order(Root -> Right);
	cout << Root -> Data; 
}
void Remove_Tree(Node* Root)
{
	if (Root == NULL) return; 
	Remove_Tree(Root -> Left);
	Remove_Tree(Root -> Right);
	delete Root;
}

int main()
{
	while (cin >> s1 >> s2)
	{
		Root = newnode();
		Recover(0, s2.size() - 1, 0, Root);
		Post_Order(Root);
		cout << endl; 
		Remove_Tree(Root);
	}
	
	return 0;
} 

