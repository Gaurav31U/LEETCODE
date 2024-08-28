class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
        vector<vector<int>> dp(1001,vector<int>(501,1));
        vector<vector<int>> dp1(1001,vector<int>(501,1));
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]-nums[j]>=0){
                    dp[i][nums[i]-nums[j]]=max(dp[i][nums[i]-nums[j]],dp[j][nums[i]-nums[j]]+1);
                    ans=max(ans,dp[i][nums[i]-nums[j]]);
                }else{
                    dp1[i][nums[j]-nums[i]]=max(dp1[i][nums[j]-nums[i]],dp1[j][nums[j]-nums[i]]+1);
                    ans=max(ans,dp1[i][nums[j]-nums[i]]);
                }
            }
        }
        return ans;
    }
};