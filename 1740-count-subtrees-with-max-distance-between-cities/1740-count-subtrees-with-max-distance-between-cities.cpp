class Solution {
public:
    vector<int> adj[16];
    bool isSubtree(vector<int> temp){
        map<int,int> mp;
        vector<int> vi;
        for(auto it:temp)mp[it]++;
        auto dfs=[&](auto&& dfs,int i,int par)->void{
            vi.push_back(i);
            for(auto it:adj[i]){
                if(mp.find(it)!=mp.end() && it!=par){
                    dfs(dfs,it,i);
                }
            }
        };
        dfs(dfs,temp[0],-1);
        if(temp.size()!=vi.size())return false;
        return true;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dis(n+1,vector<int>(n+1,0));
        int node=0;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        auto dfs=[&](auto&& dfs,int i,int d,int par)->void{
            dis[node][i]=d;
            for(auto it:adj[i]){
                if(it!=par)dfs(dfs,it,d+1,i);
            }
        };   
        for(int i=1;i<=n;i++){
            node=i;
            dfs(dfs,i,0,-1);
        }
        vector<int> ans(n-1,0);
        int t=(1<<n)-1;
        for(int i=0;i<=t;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    temp.push_back(j+1);
                }
            }
            int maxdis=0;
            if(temp.size()>1 && isSubtree(temp)){
                for(int j=0;j<temp.size();j++){
                    for(int k=0;k<temp.size();k++){
                        maxdis=max(maxdis,dis[temp[j]][temp[k]]);
                    }
                }
                if(maxdis>0)ans[maxdis-1]++;
            }
        }
        return ans;

    }
};