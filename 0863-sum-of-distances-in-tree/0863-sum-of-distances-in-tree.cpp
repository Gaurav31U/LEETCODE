class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[30001];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int vis[30001];
        memset(vis,0,sizeof(vis));
        auto dfs=[&](auto&& dfs,int i,int dis)->int{
            vis[i]=1;
            int ans=dis;
            for(auto it:adj[i]){
                if(vis[it]==0)ans+=dfs(dfs,it,dis+1);
            }
            return ans;
        };
        vector<int> ans(n,0);
        vector<int> sub(n,0);
        ans[0]=dfs(dfs,0,0);
        auto subdfs=[&](auto&& subdfs,int i)->int{
            vis[i]=1;
            int val=1;
            for(auto it:adj[i]){
                if(vis[it]==0)val+=subdfs(subdfs,it);
            }
            sub[i]=val;
            return val;
        };
        memset(vis,0,sizeof(vis));
        subdfs(subdfs,0);
        auto ansdfs=[&](auto&& ansdfs,int i,int par)->void{
            vis[i]=1;
            if(par!=-1){
                int k=sub[i];
                ans[i]=ans[par];
                ans[i]+=(n-sub[i]);
                ans[i]-=sub[i];
            }
            for(auto it:adj[i]){
                if(vis[it]==0)ansdfs(ansdfs,it,i);
            }
        };
        memset(vis,0,sizeof(vis));
        ansdfs(ansdfs,0,-1);
        return ans;
    }
};