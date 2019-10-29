//SPOJ - period
//KMP找循环节 
#include <iostream>
using namespace std;

const int L = 1000001;
char s[L];
int len, Next[L];

void GetNext()
{
	int i = 0, k = -1;
	Next[0] = -1;
	while (i < len)
	{
		if (k == -1 || s[k] == s[i]) Next[++i] = ++k;
		else k = Next[k];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int kase = 1; kase <= T; kase++)
	{
		cout << "Test case #" << kase << endl;
		cin >> len >> s;
		GetNext();
		for (int i = 2; i <= len; i++)
		{
			//注意，这里的i代表长度为i的前缀而不是最后一个字符下标为i的前缀 
			int l = i - Next[i];
			if (i % l == 0 && i != l) cout << i << ' ' << i / l << endl;
		}
		cout << endl;
	}
	
	return 0;
}
//解法参考：https://www.cnblogs.com/chenxiwenruo/p/3546457.html
//定理：假设S的长度为len，则S存在最小循环节，循环节的长度L为len-next[len]，子串为S[0…len-next[len]-1]。
//(1)如果len可以被len-next[len]整除，则表明字符串S可以完全由循环节循环组成，循环周期T=len/L。
//(2)如果不能，说明还需要再添加几个字母才能补全。需要补的个数是循环个数L-len%L，其中L=len-next[len]。(L-len%L=L-(len-L)%L=L-next[len]%L)
//
//另：听说判断循环节也可以用哈希做，求出哈希值以后直接枚举循环节长度并逐一检验即可。单个字符串的时间复杂度
//是调和级数求和≈O(nlogn)，但是这样的话，此题中每个子串必须分别求一次，导致TLE。故此种解法从略。 

