//SPOJ - a needle in the haystack
//KR
#include <list>
#include <cstdio>
#include <iterator>
#include <cctype>
using namespace std;

bool Read(char& c)
{
	c = getchar();
	while (!isalpha(c) && c != '\n') c = getchar();
	return c != '\n'; //防止越过第三行读入下一笔测资的输入数据 
}

int len;
char* p; //pattern
list<char> t; //text
bool BF() //KR算法需要借助BF完成单次比较 
{
	int j = 0;
	list<char>::iterator i = t.begin();
	while (j < len)
	{
		if (*i == p[j]) {i++; j++;}
		else return 0;
	}
	return 1;
}

int main()
{
	unsigned int ht = 0, hp = 0;
	bool First = 1;
	while (scanf("%d", &len) == 1)
	{
		if (!First) printf("\n");
		else First = 0;
		ht = hp = 0;
		t.clear();
		
		p = new char [len+1];
		scanf("%s", p);
		for (int i = 0; i < len; i++) hp = (hp << 1) + p[i];
		while (getchar() != '\n') ; //过滤掉第二行和第三行之间的换行符 
		int cnt = 0;
		char c;
		while (cnt < len && Read(c)) {ht = (ht << 1) + c; t.push_back(c); cnt++;}
		if (cnt < len) {delete[] p; continue;}
		
		unsigned int d = 1;
		for (int i = 1; i < len; i++) d <<= 1;
		int pos = 0;
		while (true)
		{
			if (hp == ht && BF()) printf("%d\n", pos);
			
			if (!Read(c)) break;
			ht = (ht - (t.front()*d) << 1) + c;
			//ht = ((ht - (t.front() << len-1)) << 1) + c; 这种写法会WA，因为len-1超过类型宽度时会出现自动取模而不是自然溢出 
			t.erase(t.begin()); t.push_back(c);
			pos++;
		}
		
		delete[] p;
	}
	
	return 0;
}

