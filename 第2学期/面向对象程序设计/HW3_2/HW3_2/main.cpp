#include <iostream>
#include "accumulate.h"
#include "minmax.h"
#include "output.h"
#include <cstdlib>
#include <string>

using std::string;
using std::cout; using std::endl;

const int N = 10;
int a[N];
double b[N];
string c[N];

int main()
{
	srand(19260817); //初始化随机数种子
	for (int i = 0; i < N; i++) a[i] = rand(); //生成[0, RAND_MAX]范围内的int随机数
	for (int i = 0; i < N; i++) b[i] = rand() / (double)RAND_MAX; //生成[0, 1]范围内，double类型的随机数
	for (int i = 0; i < N; i++)
	{
		int st = rand() / (double)RAND_MAX * 25; //指代这个字符串的首字母，[0, 25]
		int len = rand() / (double)RAND_MAX * 24 + 1; //这个字符串的长度，[1, 25]
		c[i].resize(len);
		for (int j = 0; j < len; j++) c[i][j] = 'a' + (st + j) % 26;
	} //生成随机的、只由小写字母组成的string

	cout << "the integer list: "; output(a, a + N);
	cout << "the sum of the integer list: " << accumulate(a, a + N, 0) << endl;
	cout << "the max element in the integer list: " << max_element<int*, int>(a, a + N) << endl;
	cout << "the min element in the integer list: " << min_element<int*, int>(a, a + N) << endl;
	//由于参数中不涉及函数定义中的class X，因此系统无法自动判断X为int，因此我们调用时必须显式地声明X代表int类型

	cout << "the double list: "; output(b, b + N);
	cout << "the sum of the double list: " << accumulate(b, b + N, 0.0) << endl;
	cout << "the max element in the double list: " << max_element<double*, double>(b, b + N) << endl;
	cout << "the min element in the double list: " << min_element<double*, double>(b, b + N) << endl;

	cout << "the string list: "; output(c, c + N);
	cout << "the concatenation of the string list: " << accumulate(c, c + N, string()) << endl;
	//第三个参数中注意std::string构造函数的用法
	//string()或string(0, ' ')返回一个空的字符串，string(0)（相当于给string赋值0）是非法的
	//当然，如果直接将第三个参数写成""，它会被默认认为是char*类型，编译不通过
	cout << "the max string in the string list: " << max_element<string*, string>(c, c + N) << endl;
	cout << "the min string in the string list: " << min_element<string*, string>(c, c + N) << endl;

	//getchar();
	return 0;
}
