//10.131.235.233 - 排序集合 
//递归求解 
#include <iostream>
using namespace std;

int n;
bool fir = 1;
void Solve(int cur, int k) //求解{cur, cur+1, ..., n}的第k小的子集 
{
	if (k == 1) return; //最小的子集：空集 
	int b = 1 + (1 << n-cur); //如果k>b，则答案中没有cur，因为只有第二小到第b小的子集中包含cur 
	if (k > b) Solve(cur+1, k-b+1); //不选cur 如果不选cur，则待求子集是{cur+1, ..., n}的第(k-b+1)小的子集 
	else { //选cur 
		if (fir) fir = 0;
		else printf(" ");
		printf("%d", cur);
		Solve(cur+1, k-1); //如果选择cur，则待求子集的其余部分是{cur+1, ..., n}的第(k-1)小的子集 
	}
}

int main()
{
	int k;
	cin >> n >> k;
	
	Solve(1, k);
	if (fir) printf("0");
	printf("\n");
	return 0;
}

