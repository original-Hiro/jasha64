//leetcode - evaluate reverse polish notation
//求给定的后缀表达式的值，只需用一个栈，遇到操作数入栈，遇到操作符取出栈顶两个数计算后重新入栈即可 
class Solution {
public:
    int evalRPN(const vector<string>& tokens)
	{
        stack<int> s;
        istringstream is;
        for (auto str : tokens)
        {
            if (str.size() == 1 && !isdigit(str[0]))
            {
                char op = str[0];
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                int c;
                switch (op)
                {
                    case '+': c = a+b; break;
                    case '-': c = b-a; break; //减(除)法注意被减(除)数是后出栈的那个数，注意运算顺序 
                    case '*': c = a*b; break;
                    default: c = b/a; break; //case '/'
                }
                s.push(c);
            }
            else {
                is.str(str);
                int c; is >> c; s.push(c);
                is.clear();
            }
        }
        return s.top();
    }
};

