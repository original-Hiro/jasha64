#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node() {data = 0; next = NULL;}
} *root;
inline Node* newnode() {return new Node();} 

inline void Init()
{
	int n, i, cache;
	Node *p;
	root = newnode();
	cin >> n;
	for (i = 0; i < n; i++)
	{
		p = newnode();
		scanf("%d", &cache);
		p -> data = cache;
		p -> next = root -> next;
		root -> next = p;
	}
}
inline void Insert(const int& pos, const int& elem)
{
	if (root -> next == NULL)
	{
		if (pos == 1)
		{
			Node* p = newnode();
			p -> data = elem;
			root -> next = p;
			printf("insert OK\n");
		}
		else printf("insert fail\n");
		return;
	}
	if (pos == 1)
	{
		Node* p = newnode();
		p -> data = elem;
		p -> next = root -> next;
		root -> next = p;
		printf("insert OK\n");
		return;
	}
	int i;
	Node* p = root;
	for (i = 1; i < pos; i++)
	{
		if (p -> next == NULL) {printf("insert fail\n"); return;}
		p = p -> next;
	}
	if (p -> next == NULL) {printf("insert fail\n"); return;}
	Node* cache = newnode();
	cache -> data = elem;
	cache -> next = p -> next;
	p -> next = cache;
	printf("insert OK\n");
}
inline void Get(const int& pos)
{
	if (root -> next == NULL) {printf("get fail\n"); return;}
	if (pos == 1) {printf("%d\n", root -> next -> data); return;}
	int i;
	Node* p = root;
	for (i = 0; i < pos; i++)
	{
		if (p -> next == NULL) {printf("get fail\n"); return;}
		p = p -> next;
	}
	printf("%d\n", p -> data);
}
inline void Delete(const int& pos)
{
	if (root -> next == NULL) {printf("delete fail\n"); return;}
	if (pos == 1)
	{
		Node* p = root -> next;
		root -> next = p -> next;
		delete p;
		printf("delete OK\n");
		return;
	}
	int i;
	Node* p = root;
	for (i = 1; i < pos; i++)
	{
		if (p -> next == NULL) {printf("delete fail\n"); return;}
		p = p -> next;
	}
	if (p -> next == NULL) {printf("delete fail\n"); return;}
	Node* cache = p -> next;
	p -> next = cache -> next;
	delete cache;
	printf("delete OK\n");
}
inline void Show()
{
	if (root -> next == NULL) {printf("Link list is empty\n"); return;}
	printf("%d", root -> next -> data);
	if (root -> next != NULL)
	{
		Node* p = root -> next;
		while (p -> next != NULL)
		{
			p = p -> next;
			printf(" %d", p -> data);
		}
	}
	printf("\n");
}

int main()
{
	int argc, i, cache, cache2;
	char argv[10];
	
	Init();
	cin >> argc;
	for (i = 0; i < argc; i++)
	{
		scanf(" %s", argv);
		if (argv[0] == 's') Show();
		else if (argv[0] == 'g') {scanf("%d", &cache); Get(cache);}
		else if (argv[0] == 'd') {scanf("%d", &cache); Delete(cache);}
		else {scanf("%d%d", &cache, &cache2); Insert(cache, cache2);}
	}
	
	return 0;
}

