class Solution {
public:
    long long appealSum(string s) {
        long long ans=0;
        int n=s.length();
        vector<long long> dp(n+1,0);
        vector<long long> lastIndex(26, -1);
        for(int i =0; i < n; i++){
            int ind = s[i] - 'a';
            dp[i+1] = dp[i] + i - lastIndex[ind];
            ans += dp[i+1];
            lastIndex[ind] = i;
        }
        return ans;
    }
};