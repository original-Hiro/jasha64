//leetcode - ugly number ii
//递推解法 
//首先不难看出更大的丑数是一定可以由较小的丑数乘以2, 3, 5得到 
//虽然不能通过用当前最大丑数乘以2, 3, 5来顺序得到更大的丑数，但是有一点可以确定， 
//更大的丑数乘以2一定比更小的丑数乘以2得到的丑数更大 
//所以我们维护三个指针i2, i3, i5, 其中ik的含义是：乘以k能得到比当前最大丑数大的丑数 
//的最大丑数 
//所以每次取a[i2]*2, a[i3]*3, a[i5]*5中的最小者，就是下一个丑数，注意相应地更新三个指针 
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ugnum(1, 1);
        int i2 = 0, i3 = 0, i5 = 0;
        while (ugnum.size() < n)
        {
            int n2 = ugnum[i2] * 2, n3 = ugnum[i3] * 3, n5 = ugnum[i5] * 5;
            int nx = min(min(n2, n3), n5);
            if (nx == n2) i2++;
            if (nx == n3) i3++;
            if (nx == n5) i5++;
            //此处不能写成if... else if... else... ，因为可能不止一个会和当前求出的下一个丑数相等 
            ugnum.push_back(nx);
        }
        return ugnum.back();
    }
};
//参考资料: https://www.cnblogs.com/grandyang/p/4743837.html 

