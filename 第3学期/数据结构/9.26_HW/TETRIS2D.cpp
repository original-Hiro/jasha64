//SPOJ TETRIS2D 链表 
//此题要求在O(n)复杂度内完成，所以我们必须想出一种算法来快速完成清除一行方块的操作
//快速删除->链表，利用链表的快速删除特性，可使得删除方块的时间复杂度降至O(n) 
//遂将每一列都建成一个链表，且在每行设表头
#include <iostream>
#include <vector>
using namespace std;

const int B[7][4][4][2] =
{
	{
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
		{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {0, 3}}
	},
	{
		{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
		{{0, 1}, {1, 1}, {2, 0}, {2, 1}},
		{{0, 0}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
		{{0, 2}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
		{{0, 0}, {0, 1}, {1, 0}, {1, 1}}
	},
	{
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 1}, {0, 2}, {1, 0}, {1, 1}},
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 1}, {0, 2}, {1, 0}, {1, 1}}
	},
	{
		{{0, 0}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
		{{0, 1}, {1, 0}, {1, 1}, {2, 1}},
		{{0, 1}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 1}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
		{{0, 1}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}}
	}
};
const int scr[5] = {0, 100, 250, 400, 1000};
inline int mc(char c)
{
	switch (c)
	{
		case 'I': return 0;
		case 'J': return 1;
		case 'L': return 2;
		case 'O': return 3;
		case 'S': return 4;
		case 'T': return 5;
		default: return 6; //case 'Z': return 6;
	}
}
inline int ma(int x) {return x / 90;}
const int W = 30001, H = 120007;
struct Row;
struct Node
{
	Node *u, *d;
	Row* r;
	int c;
	Node(Row* R = NULL, int C = 0): u(NULL), d(NULL), r(R), c(C) {}
} *top[W], *bot[W];
struct Row : public vector<Node*> {
	int h;
	Row *u, *d;
	Row(int H = 0): h(H), u(NULL), d(NULL) {}
	Row* go(int);
} r[H], *null = new Row(-1); //*r[H];
Row* Row::go(int d)
{
	Row* ret = this;
	while (d < 0)
	{
		ret = ret -> d;
		if (ret == NULL) return null;
		//此处增设一个虚拟null节点，避免返回NULL产生段错误 
		//但是null的h必须设为一个不可能影响答案的值，如-1 
		//反复出现段错误时，可考虑采取该措施 
		d++;
	}
	while (d > 0) {ret = ret -> u; d--;}
	return ret;
}
//Row类利用继承实现，这样便可将r.v.push_back()简化成r.push_back()，简便性和可读性增加 
//固定表头常用数组而不是指针；数组和指针都可以用的时候，尽可能选择数组，出错率大幅降低 
Row* getPos(int pos, const int (*b)[2])
{
	Row* ret;
	int h = -1;
	for (int i = 0; i < 4; i++)
		if (i == 0 || b[i][0] != b[i-1][0])
		{
			int tc = pos + b[i][0];
			Row* tr = top[tc] -> r -> go(-b[i][1]);
			if (tr -> h > h) {h = tr -> h; ret = tr;}
		}
	return ret -> u;
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		//初始化所有列的链表，初始化各行表头 
		for (int i = 0; i < H; i++)
		{
			r[i].h = i;
			if (i < H-1) r[i].u = &r[i+1]; 
			if (i > 0) r[i].d = &r[i-1];
			r[i].clear();
		}
		for (int i = 0; i < W; i++) bot[i] = top[i] = new Node(&r[0], i);
		
		int w, n;
		cin >> w >> n;
		int res = 0;
		while (n--)
		{
			//输入方块参数，计算方块落点 
			char c;
			int pos, a;
			cin >> c >> pos >> a;
			const int (*b)[2] = B[mc(c)][ma(a)];
			Row* cur = getPos(pos, b);
			
			//将方块中每一块插入所在列链表和所在行的vector 
			vector<Row*> ful;
			for (int i = 0; i < 4; i++)
			{
				Row* tr = cur -> go(b[i][1]);
				int tc = pos + b[i][0];
				Node* tmp = new Node(tr, tc);
				tr -> push_back(tmp); top[tc] -> u = tmp; tmp -> d = top[tc]; top[tc] = tmp;
				if (tr -> size() == w) ful.push_back(tr);
			}
			
			//对已满的行，在各行表头中清除该行，在所有列的链表中删除该行的块 
			if (!ful.empty())
			{
				res += scr[ful.size()];
				for (auto cr : ful)
				{
					for (const auto& i : *cr) //这种写法生成的是对容器内对象的常引用 
					{
						i -> d -> u = i -> u;
						if (i -> u != NULL) i -> u -> d = i -> d;
						if (top[i->c] == i) top[i->c] = i -> d;
						delete i;
					}
					cr -> d -> u = cr -> u;
					if (cr -> u != NULL) cr -> u -> d = cr -> d;
				}
				/*
				源代码中有一个小问题，即每次放入方块所消去的不一定是连续几排， 
				所以我们要根据实际消去的排是否连续来计算得分，而不能只看一共消去了几排。
				当然由于测试数据较弱，没有出现这样的测试点。 
				*/
			}
		}
		
		//输出答案 
		for (Row* tmp = r[0].u; tmp != NULL; tmp = tmp -> u) tmp -> h = tmp -> d -> h + 1;
		cout << "Case #" << k << ':' << endl << res << endl << top[0] -> r -> h;
		for (int i = 1; i < w; i++) cout << ' ' << top[i] -> r -> h;
		cout << endl;
		
		//清理内存 
		for (int i = 0; i < W; i++)
			for (Node* tmp = bot[i]; tmp != NULL; )
			{
				Node* utmp = tmp -> u;
				delete tmp;
				tmp = utmp;
			}
	}
	
	return 0;
}
//参考：https://www.cnblogs.com/ichn/p/7615788.html 

