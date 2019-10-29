//leetcode - shortest palindrome
//哈希做法(56ms) （常数很大，谨慎使用哈希算法） 
//因为此题等效于求从第0个字符开始的最长回文串，所以可以采取和"最长回文子串"题中类似的哈希算法
//假设当前判断的是右端为i(偶数)回文串，那么s[1...i/2]与s[i...i/2+1]的哈希值必定相同 
//假设当前判断的是右端为i(奇数)回文串，那么s[1...i/2]与s[i...i/2+2]的哈希值必定相同 
//从大往小枚举i即得解 
const int MOD[2] = {19260817, 19660813}, L = 100001, B = 27;
class Solution {
public:
    string shortestPalindrome(string s) {
        s = ' ' + s;
        Init(s);
        int i;
        for (i = s.size()-1; i > 1; i--)
            if (i % 2 == 0 && LHash1(1, i/2) == RHash1(i, i/2+1) && LHash2(1, i/2) == RHash2(i, i/2+1)) break;
            else if (i % 2 != 0 && LHash1(1, i/2) == RHash1(i, i/2+2) && LHash2(1, i/2) == RHash2(i, i/2+2)) break;
        s = s.substr(1);
        for (int j = i; j < s.size(); j++) s = s[j++] + s;
        return s;
    }
private:
    int p[2][L], rh[2][L], lh[2][L]; //hash from right/left
    void Init(const string& s)
    {
        for (int k = 0; k < 2; k++)
        {
            int len = s.size();
            p[k][0] = 1;
            for (int i = 1; i < len; i++) p[k][i] = p[k][i-1] * B % MOD[k];
            lh[k][0] = 0;
            for (int i = 1; i < len; i++) lh[k][i] = (lh[k][i-1] * B + s[i]) % MOD[k];
            rh[k][len] = 0;
            for (int i = len-1; i > 0; i--) rh[k][i] = (rh[k][i+1] * B + s[i]) % MOD[k];
        }
    }
    int LHash1(int b, int e) {return (lh[0][e] - (long long)lh[0][b-1] * p[0][e-b+1] % MOD[0] + MOD[0]) % MOD[0];}
    int LHash2(int b, int e) {return (lh[1][e] - (long long)lh[1][b-1] * p[1][e-b+1] % MOD[1] + MOD[1]) % MOD[1];}
    int RHash1(int b, int e) {return (rh[0][e] - (long long)rh[0][b+1] * p[0][b+1-e] % MOD[0] + MOD[0]) % MOD[0];}
    int RHash2(int b, int e) {return (rh[1][e] - (long long)rh[1][b+1] * p[1][b+1-e] % MOD[1] + MOD[1]) % MOD[1];}
};
//参考资料：最长回文子串的hash解法 https://blog.csdn.net/yhyyxt/article/details/50538637 

