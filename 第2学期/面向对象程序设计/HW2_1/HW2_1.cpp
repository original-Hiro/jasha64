#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::domain_error;
using std::max;

void Read(vector<string>& v, string::size_type& maxl)
{
	string s;
	while (cin >> s) {v.push_back(s); maxl = max(maxl, s.size());}
}

int main()
{
	cout << "请输入若干英文单词：" << endl;
	string::size_type maxl = 0;
	vector<string> v;
	
	try {
		//读入单词，储存读入的单词，同时统计最长单词的长度以便对齐输出
		Read(v, maxl);
		//检测是否得到了有效的输入，否则抛出异常
		if (v.empty()) throw domain_error("no valid input");
	}
	catch (domain_error)
	{
		//没有输入单词并抛出异常时，捕获异常，输出提示信息，返回非正常值结束程序
		cout << "未输入任何单词，请重试！" << endl;
		return 1;
	}

	//输出单词数，对齐输出单词并输出每个单词出现的次数
	cout << "单词总数：" << v.size() << endl;
	sort(v.begin(), v.end());
	cout << "每个单词出现的次数：" << endl;
	int cnt = 0;
	for (vector<string>::size_type i = 0; i < v.size(); i++)
	{
		++cnt;
		if (i == v.size()-1 || v[i] != v[i+1])
		{
			cout << v[i] << string(maxl+1-v[i].size(), ' ') << cnt << endl;
			cnt = 0;
		}
	}

	return 0;
}
