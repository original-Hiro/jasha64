#include <iostream>

int main()
{
	int n;
	std::cout << "请输入正方形的边长: ";
	std::cin >> n;
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) std::cout << " *";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	int a, b;
	std::cout << "请输入长方形的长和宽: ";
	std::cin >> a >> b;
	std::cout << std::endl;
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++) std::cout << " *";
		std::cout << std::endl; 
	}
	std::cout << std::endl;
	
	int l;
	do {
		std::cout << "请输入等腰三角形的底边长(奇数): "; std::cin >> l;
		if (l % 2 == 0) std::cout << "您输入的数据有误，请检查输入数据。" << std::endl; 
	} while (l % 2 == 0);
	std::cout << std::endl;
	int h = l/2+1, st = 1, sp = h-1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < sp; j++) std::cout << "  ";
		for (int j = 0; j < st; j++) std::cout << " *";
		std::cout << std::endl;
		st += 2; sp--;
	}
	
	//希望下一次的作业在文字描述里说清楚是不是每行开头有一个空格和每两个星号之间要加空格，因为只看图片把握不好格式啊QAQ 
	
	return 0; 
}

