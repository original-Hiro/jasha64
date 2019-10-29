#include <stdio.h>
#include <string.h>

int** CreateMatrix(int m, int n)
{
	int** R = new int* [m];
	for (int i = 0; i < m; i++) R[i] = new int [n];
	return R;
}
void InputMatrix(int m, int n, int** matrix)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) scanf("%d", &matrix[i][j]);
}
void OutputMatrix(int m, int n, int** matrix)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
		printf("\n");
	}
}
void MultiMatrix(int ma, int na, int mb, int nb, int** a, int** b, int** c)
{
	for (int i = 0; i < ma; i++) memset(c[i], 0, nb * sizeof(int));
	//注：由于c的第一维是用new申请的，会导致各个二维数组不连续，所以必须分开初始化 
	for (int i = 0; i < ma; i++)
		for (int j = 0; j < nb; j++)
			for (int k = 0; k < na; k++) c[i][j] += a[i][k] * b[k][j];
}
void FreeMatrix(int m, int n, int** matrix)
{
	for (int i = 0; i < m; i++) delete[] matrix[i];
	delete[] matrix;
}

int main()
{
	int ma, na, mb, nb;
	scanf("%d%d", &ma, &na);
	int** A = CreateMatrix(ma, na); InputMatrix(ma, na, A);
	scanf("%d%d", &mb, &nb);
	int** B = CreateMatrix(mb, nb); InputMatrix(mb, nb, B);
	
	int** C = CreateMatrix(ma, nb); MultiMatrix(ma, na, mb, nb, A, B, C);
	OutputMatrix(ma, nb, C);
	
	FreeMatrix(ma, na, A); FreeMatrix(mb, nb, B); FreeMatrix(ma, nb, C);
	return 0;
}

