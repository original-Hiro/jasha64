//leetcode - largest number
//显然应该把数字对应的字符串按照某种字典序降序来排列，然后依次连接起来，得到的答案最优 
//这种字典序的规则：（不妨设|a| < |b|） 
//如果字符串a不是字符串b的前缀，则和通常的字典序相同 
//如果是，可以采取一种偷懒的办法，直接比较a+b和b+a，若a+b < b+a，则a < b 
class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), comp);
        string ret, cur;
        for (auto c : nums)
        {
            cur.clear();
            do {
                cur += c % 10 + '0';
                c /= 10;
            } while (c > 0);
            reverse(cur.begin(), cur.end());
            ret += cur;
        }
        int i = 0;
        while (i < ret.size()-1 && ret[i] == '0') i++;
        return ret.substr(i); //去掉前导0 
    }
private:
    static bool comp(const int a, const int b)
    {
        char sa[11], sb[11];
        int len1 = sprintf(sa, "%d", a);
        int len2 = sprintf(sb, "%d", b);
        for (int i = 0; i < len1 && i < len2; i++)
            if (sa[i] != sb[i]) return sa[i] > sb[i];
        char sab[21], sba[21];
        strcpy(sab, sa); strcpy(sba, sb);
        strcat(sab, sb); strcat(sba, sa);
        return strcmp(sab, sba) > 0;
    }
};
//我们可以如下说明这种排序可以产生正确的拟序关系： 
//如果成立a+b < b+a, b+c < c+b, 求证a+c < c+a. （这里的加号是字符串连接运算符） 
//记x = |a|, y = |b|, z = |c|, 已知条件为a*10^y+b < b*10^x+a, b*10^z+c < c*10^y+b, 
//要证a*10^z+c < c*10^x+a. （这里的加号是通常的加号） 
//把已知条件中的两个式子变形即得: a / (10^x-1) < b / (10^y-1) < c / (10^z-1), 后易证 
//再通过如下步骤说明算法产生的是最优解： 
//按照上面步骤排序，假如不按照这个策略排序（即其中必有两个子串的位置发生了交换） 
//那么必然存在一个相邻的逆序对，把它们交换一下可以得到更优的解 

