//SPOJ - variable radix huffman encoding
//模拟 
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct HuffmanNode
{
	char id;
	int freq;
	string cod;
	vector<int> ch;
	friend bool operator < (const HuffmanNode& a, const HuffmanNode& b)
	{
		if (a.freq != b.freq) return a.freq < b.freq;
		return a.id < b.id;
	}
};
bool LexicographicalOrder(const HuffmanNode& a, const HuffmanNode& b) {return a.id < b.id;}

int main()
{
	int rad, n, kase = 0;
	while (cin >> rad && rad != 0)
	{
		HuffmanNode h[53] = {};
		cin >> n;
		for (int i = 0; i < n; i++) {cin >> h[i].freq; h[i].id = 'A' + i;}
		
		int n2 = n;
		if (rad != 2) while (n2 % (rad-1) != 1) n2++; //r!=2, 用"虚拟字符"补齐 
		for (int i = 0; i < n2; i++) h[i].id = 'A' + i;
		sort(h, h + n2);
		int m = n2 + (n2-1) / (rad-1), aux[10] = {}; //用归并的方法快速取得频率最低的r个字母 
		for (int k = n2, top1 = 0, top2 = n2; k < m; k++)
		{
			for (int top = 0; top < rad; top++)
				if (top2 >= k || (top1 < n2 && h[top1] < h[top2])) aux[top] = top1++;
				else aux[top] = top2++;
			h[k].id = h[aux[0]].id;
			for (int i = 0; i < rad; i++)
			{
				h[aux[i]].cod = '0' + i;
				h[k].id = min(h[k].id, h[aux[i]].id);
				h[k].ch.push_back(aux[i]);
				h[k].freq += h[aux[i]].freq;
			}
		}
		queue<int> q;
		q.push(m - 1);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (auto i : h[cur].ch) {h[i].cod = h[cur].cod + h[i].cod; q.push(i);}
			//一个字母的编码是从它的所有"混合字母"从最外层到最内层的编码依次连接而得 
		}
		
		sort(h, h + n2, LexicographicalOrder);
		int tot = 0, totlen = 0;
		for (int i = 0; i < n; i++) {tot += h[i].cod.size() * h[i].freq; totlen += h[i].freq;}
		cout << "Set " << ++kase << "; average length ";
		cout << setiosflags(ios::fixed) << setprecision(2) << (double)tot / totlen << endl;
		for (int i = 0; i < n; i++) cout << '\t' << h[i].id << ": " << h[i].cod << endl;
		cout << endl;
	}
	
	return 0;
}

