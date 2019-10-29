#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 1000007, M = 5007;
int a[N], f[M][M];

int main()
{
	int c1, c2, i, j;
	
	srand(time(NULL));
	cout << "for循环赋值，fill赋值，memset赋值速度测试" << endl;
	cout << "编译选项：-O2 -Wall -lm -std=c++11 -DLOCAL" << endl << endl;
	for (i = 0; i < N; i++) a[i] = rand();
	c1 = clock();
	cout << "1000000个元素的一维数组测试" << endl; 
	for (i = 0; i < N; i++) a[i] = 7;
	c2 = clock();
	cout << "for循环赋值所用的时间为：" << c2 - c1 << endl;
	c1 = c2;
	fill(a, a + N, -7);
	c2 = clock();
	cout << "fill赋值所用的时间为：" << c2 - c1 << endl;
	c1 = c2;
	memset(a, 0, sizeof(a));
	c2 = clock();
	cout << "memset赋值所用的时间为：" << c2 - c1 << endl << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++) f[i][j] = rand();
	c1 = clock();
	cout << "5000 x 5000的二维数组测试" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++) f[i][j] = 7;
	c2 = clock();
	cout << "for循环赋值所用的时间为：" << c2 - c1 << endl;
	c1 = c2;
	for (i = 0; i < M; i++) fill(f[i], f[i] + M, -7);
	c2 = clock();
	cout << "fill赋值所用的时间为：" << c2 - c1 << endl;
	c1 = c2;
	memset(f, 0, sizeof(f));
	c2 = clock();
	cout << "memset赋值所用的时间为：" << c2 - c1 << endl;
	
	return 0;
}

