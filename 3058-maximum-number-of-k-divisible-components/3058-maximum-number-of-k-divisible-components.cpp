class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int vis[n+1];
        memset(vis,0,sizeof(vis));
        int ans=0;
        auto dfs=[&](auto&& dfs,int i)->int{
            vis[i]=1;
            long long sum=values[i]%k;
            for(auto it:adj[i]){
                if(vis[it]==0){
                    long long q=dfs(dfs,it);
                    if(q%k==0)ans++;
                    else sum+=(q%k);
                }   
            }
            return sum%k;
        };
        int p=dfs(dfs,0);
        if(p%k==0)ans++;
        return ans;
    }
};