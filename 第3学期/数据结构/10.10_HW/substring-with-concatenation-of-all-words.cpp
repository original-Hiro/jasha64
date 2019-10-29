//leetcode - substring with concatenation of all words
//模拟 
class Solution
{
public:
    vector<int> findSubstring(string t, const vector<string>& words)
    {
        if (words.empty()) return vector<int>();
        const int lp = words.front().size(), lt = t.size();
        map<string, int> pc; //words中每个单词出现了几次 
        for (auto s : words)
        {
        	if (s.size() != lp) return vector<int>(); //输入数据不合法，返回空集 
        	if (pc.find(s) != pc.end()) pc[s]++;
        	else pc[s] = 1;
        }
        vector<int> ret;
        for (int i = 0; i < lp; i++) //对窗口左端为i+k*lp的每种情况进行讨论，i应该从0到lp-1循环，以完成所有可能情况 
        {
        	map<string, int> cc; //current count
        	int cnt = 0, L = i; //L: 窗口左端 
        	for (int j = L; j+lp <= lt; j += lp)
        	{
        		string c = t.substr(j, lp);
        		if (pc.find(c) != pc.end())
        		{
        			if (cc.find(c) != cc.end()) cc[c]++;
        			else cc[c] = 1;
        			cnt++;
        			while (cc[c] > pc[c]) //words中某个单词的出现次数超了 
        			{
        				//则一直右移窗口左端，直到这个单词的出现次数回到正常范围 
        				cc[t.substr(L, lp)]--; cnt--;
        				L += lp;
        			}
        			if (cnt == words.size()) //words中的单词出全了 
        			{
        				ret.push_back(L); //统计答案 
        				cc[t.substr(L, lp)]--; cnt--;
        				L += lp; //窗口左端右移lp，接着统计 
        			}
        		}
        		else {
        			//j位置出现了不在words中的单词 
        			L = j + lp; //可以直接把窗口左端移动到j+lp了，否则仍然会出现这个单词 
        			cc.clear(); cnt = 0;
        		}
        	}
        }
        return ret;
    }
};
//参考: https://blog.csdn.net/linhuanmars/article/details/20342851
//一开始试着用KMP写，但做不出来，遂搜之（没想到正解就是暴力，惊了） 

