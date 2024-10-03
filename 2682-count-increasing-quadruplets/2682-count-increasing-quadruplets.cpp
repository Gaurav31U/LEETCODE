class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1]+(nums[j-1]<i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i]){
                    long long l=dp[nums[j]][i];
                    long long r=(n-nums[i])-(j-dp[nums[i]][j+1]);
                    ans+=(l*r);
                }
            }
        }
        return ans;
    }
};