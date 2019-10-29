#include <cstdio>
#include <cstring>
using namespace std;

const int END_DAY[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int Start_Day[2107], Output[13][7][7];
bool Spc_Year[2107];

int main()
{
	int Y, i, j, k, w, d;
	
	for (i = 1801; i <= 2100; ++i)
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) Spc_Year[i] = true;
	Start_Day[1800] = 3;
	for (i = 1801; i <= 2100; ++i)
		Start_Day[i] = (Start_Day[i - 1] + 365 + Spc_Year[i - 1]) % 7;
	while (scanf("%d", &Y) == 1)
	{
		memset(Output, 0, sizeof(Output));
		Output[1][1][d = Start_Day[Y]] = 1;
		for (i = 1; i <= 12; ++i)
		{
			w = 1;
			for (j = 1; j <= END_DAY[i]; ++j)
			{
				Output[i][w][d++] = j;
				if (d == 7) {d = 0; ++w;}
			}
			if (i == 2 && Spc_Year[Y]) {Output[2][w][d] = 29; d = (d + 1) % 7;}
		}
		printf("                              %d                              \n\n", Y);
		printf("      January               February               March        \n");
		printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa\n");
		for (i = 1; i <= 6; ++i)
		{
			for (j = 1; j <= 3; ++j)
			{
				if (j > 1) printf("  ");
				for (k = 0; k < 7; ++k)
				{
					if (k > 0) printf(" ");
					if (Output[j][i][k]) printf("%2d", Output[j][i][k]);
					else printf("  ");
				}
			}
			printf("\n");
		}
		printf("       April                  May                   June        \n");
		printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa\n");
		for (i = 1; i <= 6; ++i)
		{
			for (j = 4; j <= 6; ++j)
			{
				if (j > 4) printf("  ");
				for (k = 0; k < 7; ++k)
				{
					if (k > 0) printf(" ");
					if (Output[j][i][k]) printf("%2d", Output[j][i][k]);
					else printf("  ");
				}
			}
			printf("\n");
		}
		printf("        July                 August              September      \n");
		printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa\n");
		for (i = 1; i <= 6; ++i)
		{
			for (j = 7; j <= 9; ++j)
			{
				if (j > 7) printf("  ");
				for (k = 0; k < 7; ++k)
				{
					if (k > 0) printf(" ");
					if (Output[j][i][k]) printf("%2d", Output[j][i][k]);
					else printf("  ");
				}
			}
			printf("\n");
		}
		printf("      October               November              December      \n");
		printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa\n");
		for (i = 1; i <= 6; ++i)
		{
			for (j = 10; j <= 12; ++j)
			{
				if (j > 10) printf("  ");
				for (k = 0; k < 7; ++k)
				{
					if (k > 0) printf(" ");
					if (Output[j][i][k]) printf("%2d", Output[j][i][k]);
					else printf("  ");
				}
			}
			printf("\n");
		}
	}
	
	return 0;
}

