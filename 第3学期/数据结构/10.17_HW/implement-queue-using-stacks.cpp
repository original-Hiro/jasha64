//leetcode - implement queue using stacks
//用两个栈实现队列的方法是，一个栈专门出队，一个栈专门入队，一旦在需要出队时发现
//出队栈为空，则把入队栈中当前所有的元素倒序移入出队栈即可。 
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {b.push(x);}
    
    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (a.empty())
            while (!b.empty()) {a.push(b.top()); b.pop();}
        int ret = a.top(); a.pop(); return ret;
    }
    
    /** Get the front element. */
    int peek()
    {
        if (a.empty())
            while (!b.empty()) {a.push(b.top()); b.pop();}
        return a.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {return a.empty() && b.empty();}
private:
    stack<int> a, b;
};

