class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)dp[i][m-1]=1;
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<n;j++){
                dp[j][i]=1;
                int l=0;
                if(grid[j][i]<grid[j][i+1]){
                    l=max(l,dp[j][i+1]);
                }
                if(j>0 && grid[j][i]<grid[j-1][i+1]){
                    l=max(l,dp[j-1][i+1]);
                }
                if(j<(n-1) && grid[j][i]<grid[j+1][i+1]){
                    l=max(l,dp[j+1][i+1]);
                }
                dp[j][i]+=l;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,dp[i][0]);
        return ans-1;

    }
};