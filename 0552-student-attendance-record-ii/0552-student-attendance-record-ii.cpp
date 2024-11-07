class Solution {
public:
    int checkRecord(int n) {
        int dp[100001][3][2];
        int md=1e9+7;
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int late,int absent)->int{
            if(i>n)return 1;
            int ans=0;
            if(dp[i][late][absent]!=-1)return dp[i][late][absent];
            
            if(absent>0)(ans+=(get(get,i+1,2,0)))%=md;
            if(late>0)(ans+=(get(get,i+1,late-1,absent)))%=md;
            
            (ans+=(get(get,i+1,2,absent)))%=md;
            return dp[i][late][absent]=ans;
        };
        return get(get,1,2,1);
    }
};