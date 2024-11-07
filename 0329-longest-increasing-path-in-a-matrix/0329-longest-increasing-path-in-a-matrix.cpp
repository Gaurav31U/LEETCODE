class Solution {
public:
    int dp[1001][1001];
    int n,m;
    int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
    void dfs(int i,int j,vector<vector<int>> &mat){
        int ans=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k],nj=j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && mat[i][j]<mat[ni][nj]){
                if(dp[ni][nj]!=-1)ans=max(ans,dp[ni][nj]+1);
                else{
                    dfs(ni,nj,mat);
                    ans=max(ans,dp[ni][nj]+1);
                }

            }
        }
        dp[i][j]=ans;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof(dp));
        n=matrix.size(),m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1)dfs(i,j,matrix);
            }
        }
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            ans=max(ans,dp[i][j]);
        }
        return ans;
    }
};