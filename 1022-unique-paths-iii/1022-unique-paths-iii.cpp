class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt=0;
        int vis[21][21];
        int n=grid.size(),m=grid[0].size();
        memset(vis,0,sizeof(vis));
        int c=0;
        for(auto it:grid)
            for(auto i:it)if(i==0)c++;
        int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
        auto dfs=[&](auto&& dfs,int i,int j,int k)->void{
            if(grid[i][j]==2){
                if(k==c){
                    cnt++;
                }
                return;
            }
            if(grid[i][j]==0)k++;
            for(int l=0;l<4;l++){
                int ni=dx[l]+i,nj=dy[l]+j;
                if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==0 && grid[ni][nj]!=-1){
                    vis[ni][nj]=1;      //
                    dfs(dfs,ni,nj,k);   //   IMPORTANT
                    vis[ni][nj]=0;      //
                }
            }
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    dfs(dfs,i,j,0);
                }
            }
        }
        return cnt;
    }
};