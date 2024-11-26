class Solution {
public:
    map<pair<pair<int,int>,pair<int,int>>,int>maps;
    int dfs(int i,int j,int i1,int j1,int n,int m,vector<vector<int>>&mat){
        if(i<0 || i>=n || j<0 || j>=m || i1<0 || i1>=n || j1>=m || j1<0){
            return 0;
        }
        if(maps.count({{i,j},{i1,j1}}))
            return maps[{{i,j},{i1,j1}}];
        auto &save=maps[{{i,j},{i1,j1}}];
        int res=0;
        int x[3]={1,1,1};
        int y[3]={-1,0,+1};
        for(int k=0;k<3;k++){  // important
            for(int p=0;p<3;p++){   // important
                int aux=mat[i1][j1];

                if(i==i1 && j==j1)
                    aux=0;
                res=max(res,aux+mat[i][j]+dfs(i+x[k],j+y[k],i1+x[p],j1+y[p],n,m,mat));
            }
        }
        return save= res;

    }
    int cherryPickup(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();
        return dfs(0,0,0,m-1,n,m,grid);
    }
};