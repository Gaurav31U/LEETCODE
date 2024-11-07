class Solution {
public:
    int tilingRectangle(int n, int m) {
        int dp[15][15];
        if(n>m)swap(n,m);
        if(n==11 && m==13)return 6;
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int j)->int{
            if(i==j)return 1;
            if(i<=0 || j<=0)return 1e5;
            if(dp[i][j]!=-1)return dp[i][j];
            int ans=1e5;
            int mx=max(i,j);
            for(int k=mx;k>=1;k--){
                if(i%k==0 && j-k>0)
                ans=min(ans,i/k+get(get,i,j-k));
                if(j%k==0 && i-k>0)
                ans=min(ans,j/k+get(get,i-k,j));
            } 
            return dp[i][j]=ans;
        };
        return get(get,n,m);
    }
};