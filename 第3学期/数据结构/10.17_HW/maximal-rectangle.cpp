//leetcode - maximal rectangle
//单调栈 
//显然要想求出最优解，每个点至少要被访问一次，如果要想总时间复杂度为O(n*n)，那么
//每个点为矩形右下角时的局部最优解要在O(1)时间内求出 
//我们思考什么样的解可能会是局部最优解，发现这样一个性质: 如果当前点的右边存在一点， 
//其对应的高度值比当前点的低，那么当前点的高度值对答案没有影响（矩形可以无损延伸 
//到当前点的左边一列），也就是说，既靠左又更高的点没有保存的必要 
//基于这一性质，对于每一行，我们设计一个栈，随着列数从小到大遍历，如果当前列的 
//高度大于栈顶记录的列数的高度（或者栈为空），则进栈当前列号，否则不断出栈并计算 
//每次出栈产生的一组解并更新答案，直到再次满足当前列高度大于栈顶记录的列数的高 
//度，然后进栈当前列号。 
//由于在任意时刻栈中列号对应的高度是随着列号增加而单调增加的，所以称为单调栈  
class Solution {
public:
    int maximalRectangle(const vector<vector<char>>& matrix)
    {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> ones(n+1, vector<int>(m, 0));
        int ret = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i-1][j] == '1') ones[i][j] = ones[i-1][j] + 1;
                else ones[i][j] = 0;
            ret = max(ret, maxAreaCurRow(ones[i]));
        }
        return ret;
    }
private:
    int maxAreaCurRow(vector<int>& heights)
    {
        if (heights.empty()) return 0;
        heights.push_back(0); //这样处理可以不用在整个循环结束以后再特判栈中剩余的元素  
        stack<int> s;
        int ret = 0;
        for (int i = 0; i < heights.size(); i++)
            if (s.empty() || heights[i] > heights[s.top()]) s.push(i);
            else {
                while (!s.empty() && heights[i] <= heights[s.top()])
                {
                    int tmp = s.top(); s.pop();
                    int w = s.empty() ? i : i-s.top()-1;
                    ret = max(ret, w * heights[tmp]);
                }
                s.push(i);
            }
        return ret;
    }
};
//https://blog.csdn.net/magicbean2/article/details/68486631
//目测这题是要用单调队列单调栈的，但是我不会写，只是以前有听说过这种算法而已，
//只能直接搜题解了QAQ 

