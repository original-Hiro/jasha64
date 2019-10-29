//leetcode - remove duplicate letters
//单调栈 
//对字符串中的每个字符s[i]而言，如果它后面有比它小的字符s[j]，则对于子串0~s[j]去除重复字符所得的答案，
//选择s[j]比选择s[i]更优，没必要保存s[i]（除非s[i]是最后一次出现）
//因此我们维护一个栈，顺序访问字符串，对每个字符，只要栈不为空而且栈顶元素比当前 
//字符大而且栈顶元素不是最后一次出现就出栈，完成出栈操作后再入栈 
//这样一来，任意时刻栈中选取的字符都是随着它们在字符串中出现的顺序而增大的（除非遇到最后一个字符） 
//栈中的元素即为选中在答案中的字符，最后将栈中的元素从底到顶依次连接即得答案 
class Solution
{
public:
    string removeDuplicateLetters(const string& str)
	{
    	int cnt['z' + 1] = {};
    	bool vis['z' + 1];
        fill(vis + 'a', vis + 'z' + 1, 1);
        int len = str.size();
        for (auto c : str) {cnt[c]++; vis[c] = 0;}
        
        stack<char> s;
        for (auto c : str)
        {
        	if (vis[c]) {cnt[c]--; continue;} 
            while (!s.empty() && cnt[s.top()] > 0 && c < s.top()) {vis[s.top()] = 0; s.pop();}
            s.push(c); cnt[c]--; vis[c] = 1;
        }
        
        string ret;
        while (!s.empty()) {ret = s.top() + ret; s.pop();}
        return ret;
    }
};

