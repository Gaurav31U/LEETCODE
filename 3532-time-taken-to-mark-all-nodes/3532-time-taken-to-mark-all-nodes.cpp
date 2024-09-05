class Solution {
public:
    vector<int> dp, ans;
    void dfs(int node, int par, vector<int> adj[]) {
        for(auto it: adj[node]) {
            if(it != par) {
                dfs(it, node, adj);
            }
        }
        for(auto it: adj[node]) {
            if(it != par) {
                if(it % 2 == 0) dp[node] = max(dp[node], 2 + dp[it]);
                else dp[node] = max(dp[node], 1 + dp[it]);
            }
        }
    }
    void dfs1(int node, int par, vector<int> adj[]) {
        int maxi = ans[node], maxi2 = 0;
        for(auto it: adj[node]) {
            if(it != par) {
                int x;
                if(it % 2) x = 1 + dp[it];
                else x = 2 + dp[it];
                if(maxi < x) {
                    maxi2 = maxi;
                    maxi = x;
                }else if(maxi == x) {
                    maxi2 = maxi;
                }else if(maxi2 < x) maxi2 = x;
            }
        }
        for(auto it: adj[node]) {
            if(it != par) {
                int x;
                if(it % 2) x = 1 + dp[it];
                else x = 2 + dp[it];
                int y;
                if(node % 2) y = 1;
                else y = 2;
                if(maxi == x) {
                    ans[it] += maxi2 + y;
                }
                else if(maxi > x) ans[it] += maxi + y;
                dfs1(it, node, adj);
            }
        }
        ans[node] = max(ans[node], maxi);
    }
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj[n];
        for(auto it: edges) adj[it[0]].push_back(it[1]), adj[it[1]].push_back(it[0]);
        dp.resize(n, 0);
        ans.resize(n, 0);
        dfs(0, -1, adj);
        dfs1(0, -1, adj);
        return ans;
    }
};