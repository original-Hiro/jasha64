//leetcode - basic calculator
//因为这题只有加号减号，所以表达式的解析可以偷懒，完全不必考虑优先级的问题 
//难点只剩下括号的处理，我们参照中缀表达式转为后缀的思路，每次遇到左括号就 
//把前面的计算结果和符号压入一个栈（类似于递归），遇到右括号就出栈一次并计算
//（和表达式转换一样，相当于把左括号之后入栈的那个式子弹出进行处理）  
class Solution {
public:
    int calculate(string str)
    {
        stack<int> si;
        stack<char> sc;
        int a = 0, b = 0; 
        char op = '+'; //相当于把s视为0+s，这样就不用特判第一个数 
        for (auto c : str)
        {
            if (isdigit(c)) b = b * 10 + c - '0';
            else if (c == '+' || c == '-')
			//加号、减号、右括号可能是一个双目运算式的终结，所以我们碰到这两类符号时需要进行一次a op= b的操作 
            {
                op == '+' ? a += b : a -= b; b = 0;
                op = c;
            }
            else if (c == '(') {si.push(a); a = 0; sc.push(op); op = '+';}
			//入栈以后a和op都要初始化为初始状态，以计算括号内的新式子 
            else if (c == ')') {
                op == '+' ? a += b : a -= b; b = 0;
                if (sc.top() == '+') a = si.top() + a;
                else a = si.top() - a;
                si.pop(); sc.pop();
            }
        }
        op == '+' ? a += b : a -= b; b = 0; //表达式访问完毕以后还有一次a op= b的操作 
        return a;
    }
};

