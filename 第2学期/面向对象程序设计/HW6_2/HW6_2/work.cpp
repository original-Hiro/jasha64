#include <iostream>
#include <string>
#include "Queue.h"
#include "Work.h"
using std::cin; using std::cout; using std::endl;
using std::string;

const string spaces(20, ' ');

void Work()
{
	int icnt = 0, ocnt = 0;
	Queue<int> q;
	int tim = 0;
	cout << spaces << "食堂某个窗口高峰期的排队状况模拟：" << endl;
	while (!q.isFull())
	{
		if (tim > 0 && tim % 25 == 0)
		{
			q.deQueue();
			cout << spaces << tim << "s：第" << ++ocnt << "人出队。" << endl;
		}
		if (tim % 8 == 0)
		{
			q.enQueue(tim);
			cout << tim << "s：第" << ++icnt << "人进队。" << endl;
		}
		tim++;
	}
	cout << spaces << "该窗口排队人数已达50人！请分流！" << endl;
	cout << string(10, ' ') << "队首人员于" << q.front() << "s入队。" << endl;
	cout << string(10, ' ') << "队尾人员于" << q.back() << "s入队。" << endl;

	cout << endl << endl;
	//赋值运算符测试
	Queue<int> q1(q), q2;
	q1.output();
	q2 = q1;
	q2.output();
}
