class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<long long,int> dp[n+1];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                long long d=(long long)nums[i]-nums[j];
                dp[i][d]++;
                if(dp[j].count(d)){
                    dp[i][d]+=dp[j][d];
                    ans+=dp[j][d];
                }
            }
        }
        return ans;
    }
};