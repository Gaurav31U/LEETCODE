class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1];
        int timer=0;
        vector<int> in(n+1,0),low(n+1,0);
        int vis[n+1];
        memset(vis,0,sizeof(vis));
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;
        auto dfs=[&](auto&& dfs,int i,int par)->void{
            in[i]=low[i]=timer++;
            vis[i]=1;
            for(auto it:adj[i]){
                if(it==par)continue;
                if(vis[it]==1){
                    low[i]=min(in[it],low[i]);
                }else{
                    dfs(dfs,it,i);
                    low[i]=min(low[i],low[it]);
                    if(low[it]>in[i]){
                        ans.push_back({i,it});
                    }
                }
            }

        };
        dfs(dfs,0,-1);
        return ans;
    }
};