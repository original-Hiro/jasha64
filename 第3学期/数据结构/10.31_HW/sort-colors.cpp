//leetcode - sort colors
//快速排序思想 
//受快速排序"划分"这一过程的启发，我们可以对这一题中的数组类似处理，把它视为watcher为1的划分过程即可 
//写出来以后发现，从左往右依次扫描比从两边往中间进行划分更简单，遂改为单向进行 
class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        for (int i = 0; i <= r; i++)
        {
            if (nums[i] == 0) swap(nums[l++], nums[i]);
            else if (nums[i] == 2) swap(nums[r--], nums[i--]);
        }
    }
};

