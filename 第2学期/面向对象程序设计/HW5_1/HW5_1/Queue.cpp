#include "Queue.h"
#include <iostream>
using std::ostream; using std::endl;

bool Queue::push(int d = 0)
{
	if (full()) return false;
	Node* nend = Newnode(d);
	if (empty()) begin = nend; //如果插入的元素是队列唯一一个元素，则此时begin == NULL，还需要更改begin指针指向这个元素
	else end->Next = nend;
	end = nend;
	cnt++;
	return true;
}
bool Queue::pop()
{
	if (empty()) return false;
	Node* nbegin = begin->Next;
	delete begin; begin = nbegin;
	cnt--;
	return true;
}
ostream& Queue::print(ostream& output) const
{
	for (Node* it = begin; it != NULL; it = it->Next) output << it->Data << ' '; //借用NULL表示越界
	output << endl;
	return output;
}
