#include <cstdio>
#include <cstring>
#include <cctype>

bool legal_c(const char* str)
{
	if (str[0] == '_') return 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if (isupper(str[i])) return 0;
		if (i < len-1 && str[i] == '_' && str[i+1] == '_') return 0;
	}
	if (str[len-1] == '_') return 0;
	return 1;
}
bool legal_java(const char* str)
{
	if (isupper(str[0])) return 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
		if (str[i] == '_') return 0;
	return 1;
}
bool legal(const char* str) {return legal_c(str) || legal_java(str);}

int main()
{
	char str[101];
	
	while (scanf("%s", str) != EOF)
	{
		if (!legal(str)) {puts("Error!"); continue;}
		int len = strlen(str);
		for (int i = 0; i < len; i++)
			if (isupper(str[i])) {putchar('_'); putchar(tolower(str[i]));}
			else if (str[i] == '_') {if (i < len-1) putchar(toupper(str[++i]));}
			else putchar(str[i]);
		putchar('\n');
	}
	
	return 0;
}

