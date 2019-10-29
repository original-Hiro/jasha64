#pragma pack(32)
#include <cstdio>
using namespace std;

struct test1
{
	char x1[17];
	short x2[2];
	int x3;
	long long x4;
};
struct test2
{
	char x1[17];
	short x2[2];
	int x3;
	long long x4;
}__attribute__((aligned(16)));

int main()
{
	printf("test1 struct size is: %d\n",sizeof(test1));
	printf("Allocate x1 on address: 0x%x\n",&(((test1*)0)->x1));
	printf("Allocate x2 on address: 0x%x\n",&(((test1*)0)->x2));
	printf("Allocate x3 on address: 0x%x\n",&(((test1*)0)->x3));
	printf("Allocate x4 on address: 0x%x\n",&(((test1*)0)->x4));
	
	printf("test2 struct size is: %d, aligned on 16\n",sizeof(test2));
	printf("Allocate x1 on address: 0x%x\n",&(((test2*)0)->x1));
	printf("Allocate x2 on address: 0x%x\n",&(((test2*)0)->x2));
	printf("Allocate x3 on address: 0x%x\n",&(((test2*)0)->x3));
	printf("Allocate x4 on address: 0x%x\n",&(((test2*)0)->x4));

	return 0;
}

