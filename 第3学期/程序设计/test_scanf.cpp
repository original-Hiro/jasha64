#include <stdio.h>

int main()
{
	int i;
	char c;
	float x;
	//scanf输入结束标志: 遇空白类字符; 已读入域宽指定的字符数; 输入的下一个字符不能参与构成正确的数据格式 
	scanf("%d%c%f", &i, &c, &x);
	//input: 123a123x.45
	printf("%d %c %f\n", i, c, x);	
	//output: 123 a 123.000000
	return 0;
}

