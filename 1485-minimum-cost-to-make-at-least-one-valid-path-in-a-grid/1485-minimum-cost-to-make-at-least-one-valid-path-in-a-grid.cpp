class Solution {
public:
    vector<vector<int>> move={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<array<int,2>> q;
        q.push({0,0});
        int ans=n*m;
        int mx=1e4;
        vector<vector<int>> cost(n,vector<int>(m,mx));
        cost[0][0]=0;
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            dfs(tp[0],tp[1],cost,grid,q);
        }
        return cost[n-1][m-1];
    }
    void dfs(int x,int y,vector<vector<int>>&cost,vector<vector<int>>&grid,queue<array<int,2>> &q){
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int i=move[k][0]+x;
            int j=move[k][1]+y;
            if(i>=0 && j>=0 && i<n && j<m){
                if(k==(grid[x][y]-1) && cost[i][j]>cost[x][y]){
                    cost[i][j]=cost[x][y];
                    q.push({i,j});
                }else if(cost[i][j]>cost[x][y]+1){
                    cost[i][j]=cost[x][y]+1;
                    q.push({i,j});
                }
            }
        }
    }
};