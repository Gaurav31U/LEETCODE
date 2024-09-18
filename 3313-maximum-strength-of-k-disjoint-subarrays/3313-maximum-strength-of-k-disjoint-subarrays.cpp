class Solution {
public:
    int m;
    vector<vector<vector<long long>>> dp;
    long long solve(int i,vector<int> &nums, int k,bool flag){
        if(k==0)return 0;
        int n=nums.size();
        if(i==n)
            if(k==0)return 0;
            else return -1e15;
        if(dp[i][k][flag]!=-1e16)return dp[i][k][flag];
        long long op1 = -1e15;
        long long ans = -1e15;
        if(flag)ans = max(ans,solve(i+1,nums,k,true));
        long long s = (m-k)%2==0?1:-1;
        long long t =nums[i]*1ll*k*(s);
        ans= max(ans,t+solve(i+1,nums,k,false));
        ans =max(ans,t+solve(i+1,nums,k-1,true));
        return dp[i][k][flag]=ans;
    }
    long long maximumStrength(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        m=k;
        int n=nums.size();
        dp = vector<vector<vector<long long>>> (nums.size(), vector<vector<long long>> (k + 1, vector<long long> (2, -1e16)));
        return solve(0,nums,k,true);
    }
};