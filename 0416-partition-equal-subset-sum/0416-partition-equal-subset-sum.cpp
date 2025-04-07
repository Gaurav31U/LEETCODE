class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto it:nums)sum+=it;
        if(sum&1)return false;
        int target=sum/2;
        int dp[201][target+1];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int t)->bool{
            if(t<0)return false;
            if(t==0)return true;
            if(i>=nums.size())return false;
            if(dp[i][t]!=-1)return dp[i][t]; 
            bool ans=false;
            ans=max(ans,get(get,i+1,t-nums[i]));
            ans=max(ans,get(get,i+1,t));
            return dp[i][t]=ans;
        };
        return bool(get(get,0,target));
    }
};