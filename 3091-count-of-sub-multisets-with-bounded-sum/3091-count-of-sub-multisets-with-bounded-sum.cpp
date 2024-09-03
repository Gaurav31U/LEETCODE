class Solution {
public:
    int countSubMultisets(vector<int>& A, int l, int r) {
        vector<int> dp(20010);
        dp[0] = 1;
        int mod = 1e9 + 7;
        unordered_map<int, int> count;
        for (int a : A)
            count[a]++;
        for (auto it = count.begin(); it != count.end(); ++it) {
            int a = it->first, c = it->second;
            for (int i = r; i > max(0, r - a); --i) {
                long v = 0;
                for (int k = 0; k < c && i - a * k >= 0; ++k) {
                    v += dp[i - a * k];
                }
                for (int j = i; j > 0; j -= a) {
                    if (j - a * c >= 0)
                        v = (v + dp[j - a * c]) % mod;
                    v = (v - dp[j] + mod) % mod;
                    dp[j] = (dp[j] + v) % mod;
                }
            }
        }
        long res = 0;
        for (int i = l; i <= r; ++i)
            res = (res + dp[i]) % mod;
        return res * (count[0] + 1) % mod;
    }
};