//leetcode - Implement strStr()
//模板题，三种方法，此处采用KR算法(AC, 4ms) 
class Solution
{
public:
    int strStr(string t, string p)
    {
        unsigned int ht = 0, hp = 0, d = 1; //text的哈希值, pattern的哈希值 
        //计算pattern的哈希值和text前缀的哈希值
        int lt = t.size(), lp = p.size();
        for (int i = 0; i < lp; i++) hp = (hp << 1) + p[i];
        for (int i = 0; i < lp; i++) ht = (ht << 1) + t[i]; 
        for (int i = 1; i < lp; i++) d <<= 1;
		//采用h(x) = x % MOD作为哈希函数，从而可以在O(1)时间内完成移动窗口时哈希函数的重新计算  
        for (int i = 0; i+lp <= lt; i++)
        {
            if (ht == hp && p == t.substr(i, lp)) return i; //如果哈希值相等，再判断字符串是否相等 
            ht = (ht-t[i]*d << 1) + t[i+lp]; //右移窗口1位并重算哈希值 
            //ht = (ht-(t[i] << lp-1) << 1) + t[i+lp] 这种写法会WA, 因为当lp-1超过类型宽度时会自动把lp取模, 而不是自然溢出 
        }
        return -1;
    }
};

