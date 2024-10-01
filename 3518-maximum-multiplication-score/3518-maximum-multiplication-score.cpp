class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long dp[5][100001];
        memset(dp,-1,sizeof(dp));
        int n=a.size();
        int m=b.size();
        auto get=[&](auto&& get,int i,int j)->long long{
            if(i>=n)return 0;
            if(j>=m)return LLONG_MIN/4;
            if(dp[i][j]!=-1)return dp[i][j];
            long long ans=LLONG_MIN/2;
            ans=max(ans,a[i]*1ll*b[j]+get(get,i+1,j+1));
            ans=max(ans,get(get,i,j+1));
            return dp[i][j]=ans;
        };
        return get(get,0,0);
    }
};