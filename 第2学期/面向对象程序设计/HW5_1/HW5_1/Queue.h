#pragma once
#include <iostream>

class Queue
{
public:
	Queue() :begin(NULL), end(NULL), cnt(0) {} //构造函数
	bool push(int); //进队
	bool pop(); //出队
	int& start() const { return begin->Data; } //访问队首元素（不允许更改）
	int& back() const { return end->Data; } //访问队尾元素（不允许更改）
	int count() const { return cnt; } //获取队列中的元素个数
	bool empty() const { return begin == NULL; } //判断队列是否为空
	bool full() const { return cnt >= 50; } //判断队列是否已满（达到50人报警）
	std::ostream& print(std::ostream&) const; //输出队列
private:
	struct Node
	{
		int Data;
		Node *Next;
		Node(int d = 0) :Data(d), Next(NULL) {}
	} *begin, *end; //队首指针、队尾指针（不是越界指针，越界指针直接借用NULL表示）
	inline Node* Newnode(int d = 0) { return new Node(d); }
	int cnt;
};
//由于allocator分配的是连续的内存空间，此题不适用