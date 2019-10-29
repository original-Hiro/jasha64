#include "Queue.h"
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;

const string spaces(20, ' ');

int main()
{
	int icnt = 0, ocnt = 0; //已入队人数，已出队人数（输出出入队人数编号用）
	Queue q;
	int tim = 0; //当前时间
	cout << spaces << "食堂某个窗口高峰期的排队状况模拟：" << endl;
	while (!q.full())
	{
		if (tim > 0 && tim % 25 == 0)
		{
			q.pop();
			cout << spaces << tim << "s：第" << ++ocnt << "人出队。" << endl;
		}
		//每25s出队一人
		if (tim % 8 == 0)
		{
			q.push(tim); //在队伍中记录的是这个人进队的时刻，方便最终的输出
			cout << tim << "s：第" << ++icnt << "人进队。" << endl;
		}
		//每8s进队一人
		//先执行出队后执行进队，以保证不会出现队伍中途达到50人但执行完while循环后不到50人导致系统不能侦测到满员的情况
		tim++;
	}
	cout << spaces << "该窗口排队人数已达50人！请分流！" << endl;
	cout << string(10, ' ') << "队首人员于" << q.start() << "s入队。" << endl;
	cout << string(10, ' ') << "队尾人员于" << q.back() << "s入队。" << endl;

	system("pause");
	return 0;
}
