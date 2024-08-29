class Solution {
public:
    vector<pair<int,int>> adj[100001];
    int vis[100001],comp[100001];
    int cnt,val;
    void dfs(int u){
        vis[u]=1;
        comp[u]=cnt;
        for(auto v:adj[u]){
            if(!vis[v.first])
                dfs(v.first);
            val&=v.second;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        cnt=1;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            val=(1<<30)-1;
            if(vis[i]==0)
                dfs(i);
            mp[cnt]=val;
            cnt++;
        }
        vector<int> ans;
        for(auto it:query){
            if(comp[it[0]]==comp[it[1]]){
                ans.push_back(mp[comp[it[0]]]);
            }else ans.push_back(-1);
        }
        return ans;
    }
};