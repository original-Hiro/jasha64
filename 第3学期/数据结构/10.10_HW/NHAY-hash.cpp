//SPOJ - a needle in the haystack
//哈希做法（第一次系统地学习哈希）(0.11s)
#include <cstdio>
#include <cstring>
using namespace std;

const int B = 27, MOD1 = 19260817, MOD2 = 19660813; //base, 双模数 
const int L = 1000001;
inline int idx(char c) {return c - 'a' + 1;}
int p1[L], p2[L]; //power
struct Str
{
	int h1[L], h2[L], len; //hash value
	char s[L];
	void Init()
	{
		len = strlen(s);
		h1[0] = h2[0] = 0;
		for (int i = 0; i < len; i++)
		{
			h1[i+1] = (h1[i] * B + idx(s[i])) % MOD1; //采用左开右闭区间来表示，防止越界 
			h2[i+1] = (h2[i] * B + idx(s[i])) % MOD2;
		}
	}
	int Hash1(int b, int e) {return (h1[e+1] - (long long)h1[b] * p1[e+1-b] % MOD1 + MOD1) % MOD1;}
	int Hash2(int b, int e) {return (h2[e+1] - (long long)h2[b] * p2[e+1-b] % MOD2 + MOD2) % MOD2;}
	bool Check(int h1, int h2, int b, int e) {return Hash1(b, e) == h1 && Hash2(b, e) == h2;}
} t; //text
char p[L];

int main()
{
	//init hash powers
	p1[0] = p2[0] = 1;
	for (int i = 1; i < L; i++) {p1[i] = p1[i-1] * B % MOD1; p2[i] = p2[i-1] * B % MOD2;}
	
	int len, hp1, hp2; //hash 1,2 of pattern
	bool First = 1;
	while (scanf("%d", &len) == 1)
	{
		if (!First) printf("\n");
		else First = 0;
		
		scanf("%s", p);
		hp1 = hp2 = 0;
		for (int i = 0; i < len; i++) {hp1 = (hp1 * B + idx(p[i])) % MOD1; hp2 = (hp2 * B + idx(p[i])) % MOD2;}
		
		scanf("%s", t.s); t.Init();
		for (int i = 0; i + len <= t.len; i++)
			if (t.Check(hp1, hp2, i, i+len-1)) printf("%d\n", i);
		//取模前的哈希值是完美哈希，取模后出错的概率很小，所以这里只要哈希值相等我们就可以认为字符串相等了 
		//由此略去了哈希值相等时的O(n)比较，使得整个算法的复杂度降为线性 
	}
	
	return 0;
}
//参考资料：耿明睿同学提供的标程; 哈希算法讲义https://www.cnblogs.com/Slager-Z/p/7807011.html
//进制基数不能含有模数的因子，而且必须大于字符对应数字的最大值 
//不要把任何字符对应到0，否则会导致诸如"ab" == "b"这样的问题（如果定义a->0的话），一般地把a-z对应到1-26比较合适 
//自然溢出取模或选择一个1e9做模数很容易被卡，建议选两个1e9，或者在考场上找出一个1e18（而且尽量选质数） 

