class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        int vis[n][m];
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)vis[i][j]=INT_MAX;
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        int ans=INT_MAX;
        auto dfs=[&](auto&& dfs,int i,int j,int t)->void{
            vis[i][j]=t;
            if(i==n-1 && j==m-1){
                ans=min(ans,t);
                return;
            }  
            for(int k=0;k<4;k++){
                int ni=dx[k]+i;
                int nj=dy[k]+j;
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(t<=moveTime[ni][nj]){
                        dfs(dfs,ni,nj,moveTime[ni][nj]+1);
                    }else if(vis[ni][nj]>t+1){
                        dfs(dfs,ni,nj,t+1);
                    }
                }
            }
        };
        dfs(dfs,0,0,0);
        return ans;
    }
};