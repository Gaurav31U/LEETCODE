class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> dependency(n, 0);
        for (size_t i = 0; i < dependencies.size(); ++i) {
            int course = dependencies[i][1] - 1;
            int prerequisite = dependencies[i][0] - 1;
            dependency[course] |= 1 << prerequisite;
        }
        vector<int> prerequisites(1 << n, 0);
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    prerequisites[i] |= dependency[j];
                }
            }
        }
        vector<int> dp(1 << n, n + 1);
        dp[0] = 0;
        for (int i = 1; i < (1 << n); ++i) {
            for (int j = i; j; j = (j - 1) & i) {
                if (count_setbit(j) > k) {
                    continue;
                }
                int already_taken = i ^ ((1 << n) - 1);
                if ((already_taken & prerequisites[j]) == prerequisites[j]) {
                    dp[i] = min(dp[i], dp[i ^ j] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
private:
    int count_setbit(int mask) {
        if (mask == 0) {
            return 0;
        }
        return 1 + count_setbit(mask & (mask - 1));
    }
};