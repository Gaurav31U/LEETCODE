class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<array<int,3>> q;
        if(grid[0][0]==1)health--;
        q.push({health,0,0});
        auto last=grid;
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        vector<vector<int>> h(n,vector<int>(m,0));
        while(!q.empty()){
            auto tp=q.top();
            q.pop();
            grid[tp[1]][tp[2]]=-1;
            h[tp[1]][tp[2]]=max(h[tp[1]][tp[2]],tp[0]);
            for(int k=0;k<4;k++){
                int x=dx[k]+tp[1];
                int y=dy[k]+tp[2];
                if(x>=0 && y>=0 && x<n && y<m){
                    if(grid[x][y]==1){
                        if(tp[0]-1>0){
                            grid[x][y]=-1;
                            q.push({tp[0]-1,x,y});
                        }
                    }else if(grid[x][y]==0){
                        grid[x][y]=-1;
                        q.push({tp[0],x,y});
                    }
                }
            }
        }
        return h[n-1][m-1]>=1;
    }
};