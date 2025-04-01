class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        long long dp[100001];
        int n=questions.size();
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto && get,int i)->long long{
            if(i>=n)return 0;
            if(dp[i]!=-1)return dp[i];
            dp[i]=max(get(get,i+1),get(get,i+questions[i][1]+1)+questions[i][0]);
            return dp[i];
        };
        get(get,0);
        return dp[0];

    }
};