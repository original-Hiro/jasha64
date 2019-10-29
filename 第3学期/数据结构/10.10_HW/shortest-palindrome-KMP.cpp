//leetcode - shortest palindrome
//KMP(4ms)
//因为KMP中Next数组的含义就是Next[i]=s[0..i-1]中前缀等于后缀的最长长度，所以我们
//把s倒过来（记为rev(s)），然后把c = s+'#'+rev(s)这个字符串求一遍Next数组（中间的
//分隔符号是防止rev(s)和s混在一起导致答案错误），这时Next[len(c)]代表的就是
//s的最长回文前缀长度，从而最后的答案是rev的前(len(s)-Next[len(c)])个字符+s。 
class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s; reverse(rev.begin(), rev.end());
        string c = s + '#' + rev;
        int* Next = new int [c.size()+1];
        GetNext(c, Next);
        return rev.substr(0, s.size() - Next[c.size()]) + s;
    }
private:
    void GetNext(const string& s, int* Next)
    {
        int len = s.size(), i = 0, k = -1;
        Next[0] = -1;
        while (i < len)
        {
            if (k == -1 || s[i] == s[k])
			{
				Next[++i] = ++k;
				if (s[i] == s[k]) Next[i] = Next[k];
			}
            else k = Next[k];
        }
    }
};

