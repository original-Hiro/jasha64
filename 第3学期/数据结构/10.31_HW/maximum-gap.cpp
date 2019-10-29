//leetcode - maximum gap
//桶排序思想 
//我们用"答案"一词代指数组排序后相邻元素之差的最大值，即所求的数值 
//首先要看出来，当且仅当所有的元素均匀分布的时候，答案取得最小值(mx - mn) / (n-1) 
//记上面的这个值为len，我们可以把元素按照值分配到大小均为len的桶里， 
//因为同一个桶里的元素两两的差值不会超过len，所以统计答案的时候，只需要统计后一个桶的最小值和前一个非空桶的最大值的差即可 
//时间复杂度O(n) 
class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2) return 0;
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        double len = (double)(mx - mn) / (n - 1); //不能用int，否则mx - mn < n-1时都会len == 0, 导致答案错误 
        if (len < 1e-6) return 0;
        int nb = (mx - mn) / len + 1; //num of blocks
        vector<int> mx_block(nb, INT_MIN), mn_block(nb, INT_MAX);
        for (auto c : nums)
        {
            int b = (c - mn) / len; //求出这个元素应该分到几号桶 
            Tension(mx_block[b], c); Relax(mn_block[b], c);
        }
        int res = 0;
        for (int i = 1, prev_mx = mx_block[0]; i < nb; i++)
        {
            if (mn_block[i] != INT_MAX) Tension(res, mn_block[i] - prev_mx);
            if (mx_block[i] != INT_MIN) prev_mx = mx_block[i];
        }
        return res;
    }
private:
    void Tension(int& a, int b) {if (a < b) a = b;}
    void Relax(int& a, int b) {if (a > b) a = b;}
};
//参考资料：https://blog.csdn.net/accepthjp/article/details/54098370 

