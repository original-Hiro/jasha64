//10.131.235.233 - 电话号码 
//记忆化搜索（是简单爆搜的优化），时间复杂度O(n*l) 
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, f[101];
string t, p[101];
int len;
inline char idx(char c)
{
	switch (c)
	{
		case 'a': case 'b': case 'c': return '1';
		case 'd': case 'e': case 'f': return '2';
		case 'g': case 'h': case 'i': return '3';
		case 'j': case 'k': case 'l': return '4';
		case 'm': case 'n': return '5';
		case 'o': case 'p': case 'q': return '6';
		case 'r': case 's': case 't': return '7';
		case 'u': case 'v': case 'w': return '8';
		default: return '9'; //case 'x' 'y' 'z' 
	}
}
bool Streql(int cur, int i) //密码串从cur位起与p[i]长度相同的子串能与p[i]匹配上 
{
	int lp = p[i].size();
	if (cur + lp > len) return 0;
	for (int j = 0; j < lp; j++)
		if (idx(p[i][j]) != t[cur + j]) return 0;
	return 1;
}
bool Search(int cur) //表示当前正在解码密码串的[cur, len)位 
{
	if (f[cur] != -1) return f[cur];
	for (int i = 0; i < n; i++)
		if (Streql(cur, i) && Search(cur + p[i].size())) return f[cur] = 1;
	return f[cur] = 0;
}

int main()
{
	cin >> n >> t; len = t.size();
	for (int i = 0; i < n; i++) cin >> p[i];
	
	memset(f, -1, sizeof(f)); f[len] = 1;
	if (Search(0)) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
//回溯法的时间复杂度难以精确分析，以下引用一个定性而不定量的论述:  
//回溯法的应用范围很广，只要能把待求解的问题分成不太多的步骤，每个步骤又只有不 
//太多的选择，都可以考虑应用回溯法。为什么说"不太多"呢？想象一棵包含L层，每层的分 
//支因子均为b的解答树，其结点数高达1 + b + b^2 + ... + b^(L-1) = (b^L - 1) / (b-1)。
//无论是b太大还是L太大，结点数都会是一个天文数字。
//——刘汝佳 《算法竞赛入门经典(第2版)》 

