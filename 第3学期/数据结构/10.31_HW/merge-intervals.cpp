//leetcode - merge intervals
//排序以后，能合并的项都挨在一起，一次遍历即可 
class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
	{
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> ret;
        int i = 0;
        while (i < intervals.size())
        {
            int b = intervals[i].start, e = intervals[i].end;
            while (i+1 < intervals.size() && interval_overlap(Interval(b, e), intervals[i+1])) e = max(e, intervals[++i].end);
            i++; ret.push_back(Interval(b, e));
        }
        return ret;
    }
private:
    static bool comp(const Interval& a, const Interval& b) //非静态成员函数是不能作为sort的第三个参数的，注意语法 
    {
        return a.start < b.start || (a.start == b.start && a.end < b.end);
    }
    bool interval_overlap(const Interval& a, const Interval& b) const
    {
        return b.start <= a.end;
    }
};

