class Solution {
public:
    int jump(vector<int>& a) {
        const int n = a.size();
        int f[n], ub = 0;
        memset(f, 0x3f, sizeof(f)); f[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (i + a[i] <= ub) continue;
            for (int j = ub + 1; j < n && j <= i + a[i]; j++) f[j] = f[i] + 1;
            ub = i + a[i];
        }
        return f[n-1];
    }
};

