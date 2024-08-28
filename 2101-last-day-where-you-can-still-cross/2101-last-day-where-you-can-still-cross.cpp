class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l=0,r=cells.size()-1;
        int ans=0;
        int grid[row][col];
        int dx[8]={-1,1,0,0};
        int dy[8]={0,0,-1,1};
        auto dfs=[&](auto&& dfs,int i,int j)->void{
            grid[i][j]=-1;
            for(int k=0;k<4;k++){
                int ni=dx[k]+i;
                int nj=dy[k]+j;
                if(ni>=0 && nj>=0 && ni<row && nj<col && grid[ni][nj]==0){
                    dfs(dfs,ni,nj);
                }
            }
        };
        while(l<=r){
            int mid=(l+r)/2;
            bool found=false;
            memset(grid,0,sizeof(grid));
            for(int i=0;i<=mid;i++){
                grid[cells[i][0]-1][cells[i][1]-1]=1;

            }
            for(int i=0;i<col;i++){
                if(grid[0][i]==0)dfs(dfs,0,i);
            }
            for(int i=0;i<col;i++)if(grid[row-1][i]==-1)found=true;
            if(found){
                ans=max(ans,mid);
                l=mid+1;   
            }else{
                r=mid-1;
            }
        }
        return ans+1;
    }
};