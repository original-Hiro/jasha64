#include <iostream>
#include <ctime>
using namespace std;

const int M = 1000000, N = 100;
//const int M = 10000, N = 10000;
//const int M = 100, N = 1000000;
//short a[M][N];
void assign_array_rows(short** a)//(short a[M][N])
{
	int i, j;
	clock_t b = clock();
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++) a[i][j] = 0;
	cout << "Assign array rows" << endl;
	cout << "Clock elapsed: " << (clock() - b) << endl;
}
void assign_array_cols(short** a)//(short a[M][N])
{
	int i, j;
	clock_t b = clock();
	for (j = 0; j < N; j++)
		for (i = 0; i < M; i++) a[i][j] = 0;
	cout << "Assign array cols" << endl;
	cout << "Clock elapsed: " << (clock() - b) << endl;
}	

int main()
{
	//short a[M][N]; //进行该实验时需要先上调栈空间限制 
	short** a = new short* [M];
	for (int i = 0; i < M; i++) a[i] = new short [N];
	
	//assign_array_rows(a);
	assign_array_cols(a);
	
	return 0;
}

