class Solution {
public:
    int trap(vector<int>& h) {
        if (h.empty()) return 0; //!
        const int n = h.size();
        int l[n], r[n];
        int res = 0;
        l[0] = h[0];
        for (int i = 1; i < n; i++) l[i] = max(l[i-1], h[i]);
        r[n-1] = h[n-1];
        for (int i = n-2; i >= 0; i--) r[i] = max(r[i+1], h[i]);
        for (int i = 0; i < n; i++) res += max(0, min(l[i], r[i]) - h[i]);
        return res;
    }
};

