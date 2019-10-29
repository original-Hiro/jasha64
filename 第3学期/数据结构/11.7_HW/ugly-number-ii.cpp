//leetcode - ugly number ii
//堆 
//因为每个丑数都可以通过更小的丑数乘2, 3, 5得到，所以我们通过这样一种方式完成丑数的递推计算：
//访问每一个丑数的时候，就把它乘以2, 3, 5得到的新丑数加入丑数列表中 
//因为"每一个丑数"一定是其后所有丑数中最小的一个，所以我们通过堆 
//来完成取出当前丑数的操作，每次访问完一个丑数则将其从堆中删除即可 
typedef long long ll;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        pq.push(1);
        while (--n)
        {
            ll cur = pq.top();
            while (!pq.empty() && cur == pq.top()) pq.pop(); //去重 
            pq.push(cur*2); pq.push(cur*3); pq.push(cur*5);
            //此处有一个坑点，虽然保证题目询问的所有丑数都在int范围内，但是按照我们这种写法， 
            //递推中间产生的某些丑数是超出了题目要求的范围的，所以要用long long存储 
            //这里我尝试过if (n2 > 0)，但是仍然WA，原因在于：
			//两个int的加减溢出确实不会跨过0，但是这里是乘法，可能溢出以后的结果仍然是正的 
            //所以乘法（或者多个int加减）防止溢出还是要开long long，不能通过判断是不是变成负的来判断溢出 
        }
        return pq.top();
        //还有一种解法是在堆外另外维护一个unordered_map用于去重 
        //这种解法看上去不太正统，但是效率更高（堆的大小变小了） 
    }
};
//此种解法的关键不在堆的使用，在于递推思路的发现 
//参考资料: https://www.acwing.com/solution/leetcode/content/286/ 

