//此题参考了题目网页上的Solution的思路 
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int i;
        for (i = a.size() - 2; i >= 0; i--)
            if (a[i+1] > a[i]) break;
        if (i == -1) {reverse(a.begin(), a.end()); return;}
        for (int j = i+1; j < a.size(); j++)
            if (a[j] > a[i] && (j == a.size() - 1 || a[j+1] <= a[i])) {swap(a[i], a[j]); break;}
        reverse(a.begin() + i+1, a.end());
    }
};
