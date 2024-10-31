class Solution {
public:
    int dp[304][304];
    int getans(int i,int j,vector<int> &ar){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>j)return 0;
        int ans=0;
        for(int k=i;k<=j;k++){
            ans=ar[i-1]*ar[k]*ar[j+1];
            ans+=(getans(i,k-1,ar)+getans(k+1,j,ar));
            dp[i][j]=max(ans,dp[i][j]);
        }
        return dp[i][j];
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        vector<int> ar;
        ar.push_back(1);
        for(auto it:nums)ar.push_back(it);
        ar.push_back(1);
        return getans(1,ar.size()-2,ar);
    }
};