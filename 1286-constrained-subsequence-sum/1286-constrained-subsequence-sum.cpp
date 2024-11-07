class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n , INT_MIN);
        deque<int> dq;
        int ans = INT_MIN;
        dp[0] = nums[0];
        dq.push_back(0);
        ans = max(ans , dp[0]);
        for(int i = 1; i < n; i++){
            dp[i] = max(0 , dp[dq.front()]) + nums[i];
            ans = max(ans , dp[i]);
            while(dq.size() && dp[dq.back()] <= dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() == i - k)
                dq.pop_front();
        }
        return ans;
    }
};