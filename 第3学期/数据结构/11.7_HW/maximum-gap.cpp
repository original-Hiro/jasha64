//leetcode - maximum gap
//基数排序 
//这题想做到线性复杂度有两种方法：用O(n)的排序；用不需要排序的O(n)算法（上周已经交过） 
//线性的排序有两种：基数排序、计数排序，后者空间复杂度O(max{nums})，只适用于数据范围有限的情况 
//基数排序则时间复杂度O(d(n+radix))，空间O(n+radix)，只要radix和d不太大都可以使用 
class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.empty()) return 0; //注意判空 
        RadixSort(nums);
        int ret = 0;
        for (int i = 1; i < nums.size(); i++) ret = max(ret, nums[i] - nums[i-1]);
        return ret;
    }
private:
    static const int M = 8, R = 256, B = 4; //lim for insertion sort; radix; bytes
    void RadixSort(vector<int>& nums)
    {
        const int n = nums.size();
        if (n <= M) {InsertionSort(nums); return;}
		//如果数组足够小则使用插入排序（但是感觉LSD基数排序不用递归，所以这一优化的效果有限） 
        vector<int> aux(n);
        //这里有一个插曲，一开始写成static vector<int> aux(n);会RE
		//从FAQ得知在这个网站上一个题的所有测资是在一次运行中测完的，由于static是一个类的所有对象共享，就容易RE
		//所以尽量不要用，或者是写成static vector<int> aux; aux.resize(n);让每个对象在调用时把它resize一遍 
		//另外，因为这个函数没有递归，而且这个数组的大小也是在安全范围内，我们就不用冒风险把它设为static了 
		//高大爷：static可以给成员函数用但最好别给局部变量用，如果开多个这种类型变量就炸了 
        int cnt[R+1];
        for (int d = 0; d < B; d++)
        {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; i++) cnt[GetDigit(nums[i], d) + 1]++;
            for (int j = 1; j < R; j++) cnt[j] += cnt[j-1];
            for (int i = 0; i < n; i++) aux[cnt[GetDigit(nums[i], d)]++] = nums[i];
            copy(aux.begin(), aux.end(), nums.begin());
        }
    }
    void InsertionSort(vector<int>& nums)
    {
        const int n = nums.size();
        for (int i = 1; i < n; i++) //有序范围为[0, i)，现将nums[i]插入到其应该处于的位置 
        {
            int j = i, c = nums[i];
            while (j > 0 && c < nums[j-1]) {nums[j] = nums[j-1]; j--;} //把[0, i)所有大于nums[i]的元素右移一格 
            nums[j] = c;
        }
    }
    int GetDigit(int a, int b) //获得a在基数R下的第b+1位 
    {
        while (b--) a /= R;
        return a % R;
    }
};

