class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int dp[2][1001], mod = 1000000007, sz = nums.size();
        fill_n(begin(dp[1]), nums[0] + 1, 1);
        for (int i = 1; i < sz; ++i) {
            for (int n = 0, sum = 0; n <= nums[i]; ++n) {
                if (int off = n + min(0, nums[i - 1] - nums[i]); off >= 0)
                    sum = (sum + dp[i % 2][off]) % mod;
                dp[!(i % 2)][n] = sum;
            }
        }
        return accumulate(begin(dp[sz % 2]), begin(dp[sz % 2]) + nums.back() + 1, 0, 
            [&](int s, int n){ return (s + n) % mod; });
    }
};