class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int ans=0;
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<m/2;j++)
                if(grid[i][j]!=grid[i][m-j-1])
                    p++;
            cnt+=p;
        }
        ans=cnt;
        cnt=0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n/2;i++){
                if(grid[i][j]!=grid[n-i-1][j])
                    cnt++;
            }
        }
        ans=min(ans,cnt);
        return ans;
    }
};