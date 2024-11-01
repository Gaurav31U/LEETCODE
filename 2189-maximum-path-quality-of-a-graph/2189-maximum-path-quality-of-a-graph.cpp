class Solution {
public:
    int max_val = 0;
    int dfs(vector<vector<pair<int, int>>> &al, vector<int> &vis, vector<int>& vals, int i, int time, int val) {
    val += (++vis[i] == 1) ? vals[i] : 0;
    if (i == 0)
        max_val = max(max_val, val);
    for (auto [j, t] : al[i])
        if (time - t >= 0)
            dfs(al, vis, vals, j, time - t, val);
    --vis[i];
    return max_val;
}
    int maximalPathQuality(vector<int>& vals, vector<vector<int>>& edges, int maxTime) {
        vector<vector<pair<int, int>>> al(vals.size());
    vector<int> vis(vals.size(),0);
    for (auto &e : edges) {
        al[e[0]].push_back({e[1], e[2]});
        al[e[1]].push_back({e[0], e[2]});
    }
    return dfs(al, vis, vals, 0, maxTime, 0);
    }
};