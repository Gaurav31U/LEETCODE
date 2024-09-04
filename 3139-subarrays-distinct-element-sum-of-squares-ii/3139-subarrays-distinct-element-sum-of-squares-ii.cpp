class Solution {
public:
    int st[400000] = {}, lazy[400000] = {}, last[100001] = {}, mod = 1000000007;
    long long query(int l, int r, int p = 1, int tl = 0, int tr = 100000) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr)
            return (st[p] + (1LL + tr - tl) * lazy[p]) % mod;
        int tm = (tl + tr) / 2;
        return (1LL + r - l) * lazy[p] + 
            query(l, min(r, tm), p * 2, tl, tm) + query(max(l, tm + 1), r, p * 2 + 1, tm + 1, tr);
    }
    void add(int l, int r, int v, int p = 1, int tl = 0, int tr = 100000) {
        if (l == tl && r == tr)
            lazy[p] += v;
        else if (l <= r) {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
            lazy[p] = 0;  
            int tm = (tl + tr) / 2;
            add(l, min(r, tm), v, p * 2, tl, tm);
            add(max(l, tm + 1), r, v, p * 2 + 1, tm + 1, tr);
            st[p] = query(tl, tm, p * 2, tl, tm) + query(tm + 1, tr, p * 2 + 1, tm + 1, tr);
        }
    }
    int sumCounts(vector<int>& nums) {
        long long sum_sq = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int l = last[nums[i]];
            long long sum = query(l, i);
            add(l, i, 1);
            sum_sq = (sum_sq + 2 * sum + (i - l) + 1) % mod;
            res = (res + sum_sq) % mod;
            last[nums[i]] = i + 1;
        }
        return res;
    }   
};