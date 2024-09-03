class Solution {
public:
    int maxTotalReward(vector<int>& rewards) {
        sort(rewards.begin(),rewards.end());
        int dp[50001];
        int n=rewards.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<rewards.size();i++)
            if(i==0 || rewards[i]!=rewards[i-1]){
                int lim=min(rewards[i],rewards.back()-rewards[i]);
                for(int j=0;j<lim;j++)
                    dp[rewards[i]+dp[j]]=rewards[i]+dp[j];
            }
        return rewards.back()+*max_element(dp,dp+rewards.back());
    }
};