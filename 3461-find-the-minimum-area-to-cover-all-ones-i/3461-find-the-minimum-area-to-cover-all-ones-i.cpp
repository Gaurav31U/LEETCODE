class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int minx=n,maxx=0,maxy=0,miny=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    minx=min(minx,i);
                    maxx=max(maxx,i);
                    miny=min(miny,j);
                    maxy=max(maxy,j);
                }
            }
        }
        return (maxx-minx+1)*(maxy-miny+1);
    }
};