//leetcode - median of two sorted arrays
//二分 
/*
"中位数"在统计学上的定义是：中位数将有序序列分成长度相同的两个子序列，其中一个子序列中的所有值大于另一个的所有值。 
有鉴于此，设m、n为序列A、B的长度，我们如果能找到一个i(0 <= i <= m)和j(0 <= j <= n)
将A序列分割成A1 = A[0...i-1]和A2 = A[i...m-1]并将B序列分割成B1 = B[0...j-1]和B2 = B[j...n-1]， 
将A1和B1放在一起得到AB1，A2和B2放在一起得到AB2，如果i和j使得AB1和AB2长度相等、AB1总是小于AB2， 
我们就得到了中位数（可由AB1中的最大值和AB2中的最小值算出）。 
欲达到这个条件，首先i + j == (m + n + 1) / 2，即j = (m+n+1) / 2 - i，使得长度相等 
（显然j <= n成立；为确保j >= 0，已知i <= m，则要求m <= n） 
然后，因为已经成立A1 < A2和B1 < B2，只要A1 < B2并且A2 < B1就能满足第二个条件，也就是 
A[i-1] <= B[j] && B[j-1] <= A[i]。（i, j == 0, m 或 n 的边界情况特判） 
这样就得到了一种顺序求解方法：i = 0 ... m-1，依次判断i和对应的j是不是解。 
因为A和B都是排好序的，随着i增大，A[i-1]和A[i]变大，B[j]和B[j-1]减小，这是有单调性的， 
由此就可以写出二分：分类讨论对于每组i, j可能遇到的情况 
如果B[j-1] > A[i]，说明A[i]太小，则令Low = i + 1； 
如果A[i-1] > B[j]，说明A[i-1]太大，则令High = i - 1； 
如果上面两种情况都不出现，则满足上面所说的第二个条件，则我们求出了解。  
*/
class Solution
{
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (nums1.empty()) return findMedian(nums2);
        if (nums2.empty()) return findMedian(nums1);
        if (n < m) return findMedianSortedArrays(nums2, nums1);
        int Low = 0, High = m, halfLen = (m + n + 1) / 2;
        while (Low <= High)
        {
            int i = (Low + High) / 2, j = halfLen - i;
            if (i < High && nums2[j-1] > nums1[i]) Low = i + 1;
            else if (i > Low && nums1[i-1] > nums2[j]) High = i - 1;
            else {
                int maxLeft = i > 0 ? nums1[i-1] : -0x7fffffff;
                if (j > 0) maxLeft = max(maxLeft, nums2[j-1]); //求出AB1的最大值 
                if ((m + n) % 2 == 1) return maxLeft;
                int minRight = i < m ? nums1[i] : 0x7fffffff;
                if (j < n) minRight = min(minRight, nums2[j]); //求出AB2的最小值 
                return (maxLeft + minRight) / 2.0;
            }
        }
    }
private:
    double findMedian(const vector<int>& nums)
    {
        int sz = nums.size();
        if (sz == 1) return nums[0];
        if (sz % 2 == 0) return (nums[sz/2] + nums[sz/2-1]) / 2.0;
        else return nums[sz/2];
    }
};
//参考资料：leetcode solution 

