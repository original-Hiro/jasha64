#include "postgres.h"
#include "executor/executor.h"
#include <ctype.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

//是否忽略大小写
#define PGSJ_IGNORE_CASE 1
//jaccard index计算时用于单词首尾的填充符，默认为'\0'
#define PGSJ_FILLING_CHAR 0
PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(levenshtein_distance);
Datum
levenshtein_distance(PG_FUNCTION_ARGS)
{
	const VarChar* vc1 = PG_GETARG_VARCHAR_PP(0);
	const VarChar* vc2 = PG_GETARG_VARCHAR_PP(1);
	const char* t1 = VARDATA_ANY(vc1);
	const char* t2 = VARDATA_ANY(vc2);
	int l1 = VARSIZE_ANY_EXHDR(vc1), l2 = VARSIZE_ANY_EXHDR(vc2);
	//递推
	int32 f[2][201];
	for (int j = 0; j <= l2; j++) f[0][j] = j;
	for (int i = 1; i <= l1; i++)
	{
		int k = i & 1;
		f[k][0] = i;
		for (int j = 1; j <= l2; j++)
		{
			int cur_cost = PGSJ_IGNORE_CASE ?
				tolower(t1[i-1]) != tolower(t2[j-1]) :
				t1[i-1] != t2[j-1];
			f[k][j] = min(f[k^1][j], f[k][j-1]) + 1;
			f[k][j] = min(f[k][j], f[k^1][j-1] + cur_cost);
		}
	}
	PG_RETURN_INT32(f[l1&1][l2]);
}

static bool H[128][128]; //用作哈希表的布尔数组
PG_FUNCTION_INFO_V1(jaccard_index);
Datum
jaccard_index(PG_FUNCTION_ARGS)
{
	const VarChar* vc1 = PG_GETARG_VARCHAR_PP(0);
	const VarChar* vc2 = PG_GETARG_VARCHAR_PP(1);
	const char* t1 = VARDATA_ANY(vc1);
	const char* t2 = VARDATA_ANY(vc2);
	int l1 = VARSIZE_ANY_EXHDR(vc1), l2 = VARSIZE_ANY_EXHDR(vc2);
	int ins = 0, uni = 0; //统计集合交和并的大小
	memset(H, 0, sizeof(H));
	for (int i = 0; i <= l1; i++)
	{
		int k1 = i == 0 ? PGSJ_FILLING_CHAR :
			PGSJ_IGNORE_CASE ? tolower(t1[i-1]) : t1[i-1];
		//含义：如果下标为0或l1，就用设定字符填充；
		//如果设置了忽略大小写，则访问哈希表时把大写字母统一转换成小写字母。
		int k2 = i == l1 ? PGSJ_FILLING_CHAR :
			PGSJ_IGNORE_CASE ? tolower(t1[i]) : t1[i];
		H[k1][k2] = 1; uni++;
	}
	for (int j = 0; j <= l2; j++)
	{
		int k1 = j == 0 ? PGSJ_FILLING_CHAR :
			PGSJ_IGNORE_CASE ? tolower(t2[j-1]) : t2[j-1];
		int k2 = j == l2 ? PGSJ_FILLING_CHAR :
			PGSJ_IGNORE_CASE ? tolower(t2[j]) : t2[j];
		if (H[k1][k2]) ins++; //该bigram在前一个字符串中也出现了
		else {H[k1][k2] = 1; uni++;} //该bigram在前一个字符串中未出现
	}
	PG_RETURN_FLOAT8(ins / (double)uni);
}

