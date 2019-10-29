//leetcode - search in rotated sorted array
/*
首先通过二分查找找到最大值点（因为我们可以通过讨论nums[low], nums[mid], nums[high]
三点的大小关系知道最大值所在区间），然后在nums分成的两段有序区间内分别二分查找即可 
*/
class Solution
{
public:
    int search(const vector<int>& nums, int target)
    {
        if (nums.empty()) return -1;
        int mx = getMaximum(nums);
        int r1 = binarySearch(nums, 0, mx, target), r2 = binarySearch(nums, mx+1, nums.size()-1, target);
        return r1 == -1 ? r2 : r1;
    }
private:
    int getMaximum(const vector<int>& nums)
    {
    	//二分搜索的变式还是很多的，如果可以只通过mid一点的信息判断下一步应搜索区间，那么写法可以简单很多 
    	//然而此处必须用到至少两个点的信息，所以只能使用这种略显丑陋的写法了 
        int Low = 0, High = nums.size()-1, ret;
        if (nums[Low] < nums[High]) return High;
        while (Low + 1 < High) //如果Low == High 或 Low + 1 == High了，这时候三个点会出现重点，宜停止二分搜索 
        {
            int Mid = (Low + High) / 2;
            if (nums[Low] < nums[Mid]) Low = Mid;
            else High = Mid - 1;
        }
        return nums[Low] < nums[High] ? High : Low;
    }
    int binarySearch(const vector<int>& nums, int Low, int High, int target)
    {
    	//此处只需要Mid一点的信息，所以不用像上面那么麻烦了 
        while (Low <= High)
        {
            int Mid = (Low + High) / 2;
            if (target == nums[Mid]) return Mid;
            else if (target < nums[Mid]) High = Mid - 1;
            else Low = Mid + 1;
        }
        return -1;
    }
};

