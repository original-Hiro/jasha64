//SPOJ - a needle in the haystack
//KMP(0.10s)
#include <cstdio>
#include <cctype>
using namespace std;

bool Read(char& c)
{
	c = getchar();
	while (!isalpha(c) && c != '\n') c = getchar();
	return c != '\n'; //防止越过第三行读入下一笔测资的输入数据 
}

int len;
int* Next;
char* p; //pattern
//按照题目所说，p可能是个非常大的数组，故不得不放在全局变量 
void GetNext()
{
	int i = 0, k = -1;
	Next[0] = -1;
	while (i < len) //因为需要在每找到一个匹配点的时候执行失配操作来继续查找，所以此处将Next[]的定义域从[0, len)拓展到[0, len] 
	{
		if (k == -1 || p[i] == p[k])
		{
			Next[++i] = ++k;
			if (p[i] == p[k]) Next[i] = Next[k];
		}
		else k = Next[k];
	}
}

int main()
{
	bool First = 1;
	while (scanf("%d", &len) == 1)
	{
		if (!First) printf("\n");
		else First = 0;
		
		p = new char [len+1];
		scanf("%s", p);
		Next = new int [len+1];
		GetNext();
		while (getchar() != '\n') ; //过滤掉第二行和第三行之间的换行符 
		
		//for (int i = 0; i <= len; i++) printf("%d ", Next[i]);
		//交作业时记得注释调试输出 
		
		char c;
		int i = 0, j = 0;
		while (true)
		{
			if (c == p[j])
			{
				if (++j == len)
				{
					printf("%d\n", i-len);
					j = Next[j];
				}
				i++;
				if (!Read(c)) break;
			}
			else if (Next[j] != -1) j = Next[j];
			else {
				i++;
				if (!Read(c)) break;
				j = 0;
			}
		}
		
		delete[] p;
	}
	
	return 0;
}

