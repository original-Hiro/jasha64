//leetcode - minimum number of refueling stops
//贪心 
//首先要看出这样一个结论：只要一个加油站是可抵达的，那么它的位置不影响它对答案的贡献 
//接下来就可以想出算法：维护当前油量tank，每次往前走一个加油站的距离， 
//如果到达某个加油站的时候tank<0了，则我们选择从之前到过（也就是现有油量允许到达） 
//的所有加油站中，选出油量最大的，在那里加油 
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
    {
        int tank = startFuel;
        priority_queue<int> pq; //priority_queue默认是大根堆，越小的整数优先级越低 
        int cnt = 0, prev = 0; //用prev变量即可避免对于"当前车站是否是第0个"的讨论，代码更美观 
        for (auto station : stations)
        {
            int dis = station[0] - prev;
            tank -= dis;
            while (tank < 0) //因为可能不止加油一次，所以要用while而不是if 
            {
                if (pq.empty()) return -1;
                tank += pq.top(); pq.pop();
                cnt++;
            }
            pq.push(station[1]); prev = station[0];
        }
        int dis = target - prev;
        tank -= dis;
        while (tank < 0)
        {
            if (pq.empty()) return -1;
            tank += pq.top(); pq.pop();
            cnt++;
        }
        return cnt;
    }
};
//参考资料：leetcode的solution 

