class Solution{
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> parent, size;
    int m, n;

    bool isValidCo(int& x, int& y){
        return x>=0 && x<m && y>=0 && y<n;
    }

    int getKey(int& x, int& y){
        return x*n + y + 1;
    }

    int findParent(int p){
        if(parent[p]==p)
            return p;
        
        return parent[p] = findParent(parent[p]);
    }

    void connect(int u, int v){
        int p1 = findParent(u);
        int p2 = findParent(v);

        if(p1==p2)
            return;
        
        if(size[p1] > size[p2]){
            parent[p2] = p1;
            size[p1] += size[p2];
        }
        else{
            parent[p1] = p2;
            size[p2] += size[p1];
        }
    }

    void connectNeighbours(vector<vector<int>>& grid, int& x, int& y){
        int key = getKey(x, y);
        for(int i=0; i<4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(isValidCo(nx, ny) && grid[nx][ny]==1)
                connect(key, getKey(nx, ny));
        }

        if(x==0)
            connect(0, key);
    }

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits){
        m=grid.size(), n=grid[0].size();

        for(vector<int>& h:hits){
            if(grid[h[0]][h[1]]==1)
                grid[h[0]][h[1]] = -1;
        }

        size.resize(m*n + 1, 1);
        parent.resize(m*n + 1);
        for(int i=0; i<=m*n; i++)
            parent[i] = i;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    connectNeighbours(grid, i, j);
            }
        }

        int stableBricks = size[findParent(0)], newStableBricks;
        vector<int> res(hits.size());
        for(int i=hits.size()-1; i>=0; i--){
            int x=hits[i][0], y=hits[i][1];

            if(grid[x][y] == -1){
                grid[x][y] = 1;
                connectNeighbours(grid, x, y);
                newStableBricks = size[findParent(0)];
                res[i] = max(0, newStableBricks - stableBricks - 1);
                stableBricks = newStableBricks;
            }
        }

        return res;
    }
};