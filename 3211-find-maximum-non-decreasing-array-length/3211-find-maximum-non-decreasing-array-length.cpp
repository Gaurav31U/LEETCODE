class Solution {
public:
    int findMaximumLength(vector<int>& A) {
        int n = A.size();
        vector<int> pre(n + 2), dp(n + 1);
        vector<long long> acc(n + 1);
        for (int i = 1; i <= n; i ++) {
            acc[i] = acc[i - 1] + A[i - 1];
        }
        for (int i = 0, j = 1; j <= n; j++) {
            i = max(i, pre[j]); // if this was previously optimizesd.
            dp[j] = dp[i] + 1;
            int k = lower_bound(acc.begin(), acc.end(), 2 * acc[j] - acc[i]) - acc.begin();
            pre[k] = j;
        }
        return dp[n];
    }
};