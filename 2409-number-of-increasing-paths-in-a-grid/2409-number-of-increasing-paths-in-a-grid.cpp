class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int md=1e9+7;
        int n=grid.size(),m=grid[0].size();
        int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
        int ans=0;
        int dp[n][m];
        vector<pair<int,pair<int,int>>> vi;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vi.push_back({grid[i][j],{i,j}});
                dp[i][j]=1;
            }
        }
        sort(vi.begin(),vi.end());
        auto dfs=[&](auto&& dfs,int i,int j)->void{
            for(int k=0;k<4;k++){
                int ni=dx[k]+i;
                int nj=dy[k]+j;
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]>grid[i][j]){
                    (dp[ni][nj]+=dp[i][j])%=md;
                }
            }
        };
        for(auto it:vi){
            dfs(dfs,it.second.first,it.second.second);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                (ans+=dp[i][j])%=md;
            }
        }
        return ans;
    }
};