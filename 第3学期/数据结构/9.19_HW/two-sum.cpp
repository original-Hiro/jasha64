class Solution
{
public:
	vector<int> twoSum(vector<int>& v, int t)
	{
		vector<int> ord;
		for (int i = 0; i < v.size(); i++) ord.push_back(i);
		sort(ord.begin(), ord.end(), [&](int a, int b){return v[a] < v[b];});
		//匿名函数
		//[&]表示用到的外部变量均按引用传递 
		//完整的语句是: [&](int a, int b) -> bool {return v[a] < v[b];}, 由于函数体只有一个return语句, 因此可以省略返回值类型 
		
		//利用单调性，这一步时间复杂度O(n) 
		for (int i = 0, j = v.size() - 1; i < j; i++)
		{
			while (i < j && v[ord[i]] + v[ord[j]] > t) j--;
			if (i < j && v[ord[i]] + v[ord[j]] == t) return (vector<int>){ord[i], ord[j]};
		}
	}
};

