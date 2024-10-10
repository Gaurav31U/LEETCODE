class Solution {
public:
    int MAX=1000000000;
    int maximumMinutes(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        auto bound_check = [n,m](int i, int j){ return i>=0 && i<n && j>=0 && j<m; };
        deque<tuple<int, int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0)
                    grid[i][j]=MAX;
                else if(grid[i][j]==1)
                    q.emplace_back(i,j,0);
                else
                    grid[i][j]=-1;
            }
        }
        while(!q.empty()){
            auto [i,j,t] = q.front();
            q.pop_front();
            grid[i][j]=t;
            array<pair<int,int>, 4> expand = {{{i+1,j}, {i-1,j}, {i,j+1}, {i,j-1}}};
            for(auto [r,c] : expand){
                if(bound_check(r,c) && grid[r][c]!=-1 && grid[r][c]==MAX)
                    q.emplace_back(r,c,t+1);
            }
        }
        deque<tuple<int, int, int, int>> qq;
        qq.emplace_back(0,0,0, grid[0][0]-1);
        while(!qq.empty()){
            auto [i,j,t,w] = qq.front();
            qq.pop_front();
            grid[i][j]=-1;
            t++;
            array<pair<int,int>, 4> expand = {{{i+1,j}, {i-1,j}, {i,j+1}, {i,j-1}}};
            for(auto [r,c] : expand){
                if(r == n-1 && c == m-1){
                    int tmp = min(w, grid[r][c]-t);
                    if(tmp > n*m) return MAX;
                    return tmp;
                }
                if(bound_check(r,c) && grid[r][c]!=-1 && t < grid[r][c]){
                    if(grid[r][c] -t -1 >= w)
                        qq.emplace_front(r,c,t, w);
                    else
                        qq.emplace_back(r,c,t, grid[r][c] -t -1);
                }
            }
        }
        return -1;
    }
};