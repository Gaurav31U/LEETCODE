class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int dp[51][1001];
        int md=1e9+7;
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int t)->int{
            if(t<0)return 0;
            if(t==0)return 1;
            if(i>=types.size()){
                if(t==0)return 1;
                return 0;
            }
            if(dp[i][t]!=-1)return dp[i][t];
            long long ans=0;
            int c=types[i][0];
            int m=types[i][1];
            for(int j=0;j<=c;j++){
                (ans+=get(get,i+1,t-j*m))%=md;   
            }
            return dp[i][t]=ans;
        };
        return get(get,0,target);
    }
};