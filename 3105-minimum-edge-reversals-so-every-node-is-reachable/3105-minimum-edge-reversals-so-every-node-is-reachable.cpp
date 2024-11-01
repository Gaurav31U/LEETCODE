class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> adj1[100001],adj2[100001];
        for(auto it:edges){
            adj1[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        int vis[100001];
        int node=0;
        int cnt=0;
        auto dfs=[&](auto&& dfs,int i)->void{
            vis[i]=1;
            for(auto it:adj1[i]){
                if(vis[it]==0){
                    dfs(dfs,it);
                }
            }
            for(auto it:adj2[i]){
                if(vis[it]==0){
                    cnt++;
                    dfs(dfs,it);
                }
            }
        };
        memset(vis,0,sizeof(vis));
        dfs(dfs,node);
        vector<int> ans(n,0);
        ans[node]=cnt;
        auto ansdfs=[&](auto&& ansdfs,int i,int par,int edge)->void{
            vis[i]=1;
            if(par!=-1){
                if(edge==1){
                    ans[i]=ans[par]+1;
                }else{
                    ans[i]=ans[par]-1;
                }

            }
             for(auto it:adj1[i]){
                if(vis[it]==0){
                    ansdfs(ansdfs,it,i,1);
                }
            }
            for(auto it:adj2[i]){
                if(vis[it]==0){
                    // cnt++;
                    ansdfs(ansdfs,it,i,0);
                }
            }
        };
        memset(vis,0,sizeof(vis));
        ansdfs(ansdfs,node,-1,0);
        return ans;
    }
};