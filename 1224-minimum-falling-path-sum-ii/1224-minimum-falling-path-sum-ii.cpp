class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int path=1;
        for(int i=n-2;i>=0;i--){
            auto t1=grid[i+1];
            auto t2=grid[i+1];
            for(int j=1;j<m;j++){
                t1[j]=min(t1[j],t1[j-1]);
            }
            for(int j=m-2;j>=0;j--){
                t2[j]=min(t2[j],t2[j+1]);
            }
            for(int j=0;j<m;j++){
                if(j==0){
                    grid[i][j]+=t2[j+1];
                }else if(j==m-1){
                    grid[i][j]+=t1[j-1];
                }else{
                    grid[i][j]+=min(t2[j+1],t1[j-1]);
                }
            }
        }
        int ans=grid[0][0];
        for(int i=0;i<m;i++)ans=min(grid[0][i],ans);
        return ans;
    }
};