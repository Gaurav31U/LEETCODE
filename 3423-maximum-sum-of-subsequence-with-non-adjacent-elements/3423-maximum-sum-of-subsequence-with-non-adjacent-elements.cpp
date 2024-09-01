constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();
        int sz = 1;
        while (sz < n) sz <<= 1;
        vector<array<long, 4>> tree(sz << 1, {0, 0, 0, 0});
        for (int i = 0; i < n; ++i) tree[sz + i][0] = max(nums[i], 0);
        for (int i = n; i < sz; ++i) tree[sz + i][0] = LONG_MIN;
        for (int i = sz - 1; i > 0; --i) merge(tree[i], tree[i << 1], tree[(i << 1) + 1]);
        long res = 0ll;
        for (const auto& q : queries) {
            int i = q[0] + sz;
            tree[i][0] = max(q[1], 0);
            while (i > 1) {
                i >>= 1;
                merge(tree[i], tree[i << 1], tree[(i << 1) + 1]);
            }
            res = (res + tree[1][0]) % MOD;
        }
        return res;
    }

private:
    void merge(array<long, 4>& dest, const array<long, 4>& a, const array<long, 4>& b) {
        if (b[0] == LONG_MIN) {
            dest = a;
            return;
        }
        dest[0] = max(a[2] + b[0], a[0] + b[1]);
        dest[1] = max(a[3] + b[0], a[1] + b[1]);
        dest[2] = max(a[0] + b[3], a[2] + b[2]);
        dest[3] = max(a[3] + b[2], a[1] + b[3]);
    }
};