#define ll long long
class Solution {
public:
    unordered_map<string, ll> mp;
    set<ll> uniqueLen;
    ll dp[1002];

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        ll ind = 0;
        memset(dp, 0, sizeof(dp));
        for (auto& it : original)mp[it];
        for (auto& it : changed)mp[it];
        for (auto& it : mp) {
            uniqueLen.insert(it.first.size());
            it.second = ind;
            ind++;
        }
        vector<vector<ll>> graph(ind, vector<ll>(ind, LLONG_MAX));
        for (int i = 0; i < original.size(); i++) {
            graph[mp[original[i]]][mp[changed[i]]] = min(1ll * cost[i], graph[mp[original[i]]][mp[changed[i]]]);
        }
        for (int i = 0; i < ind; i++) {
            graph[i][i] = 0;
        }
        vector<vector<ll>> adj = floydWarshall(graph);
        ll ans = f(source, target, adj);
        if (ans == LLONG_MAX) {
            return -1;
        }
        return ans;
    }
    ll f(string& original, string& target, vector<vector<ll>>& cost) {
        int n = original.size();
        for (int i = n - 1; i >= 0; i--) {
            ll ans = LLONG_MAX;
            if (original[i] == target[i]) {
                ans = dp[i + 1];
            }
            for (auto j : uniqueLen) {
                if (j + i > n) {
                    break;
                }
                string start = original.substr(i, j);
                string end = target.substr(i, j);
                ll initialCost = costToConvert(start, end, cost);
                if (initialCost == LLONG_MAX) {
                    continue;
                }
                ll futureCost = dp[i + j];
                if (futureCost == LLONG_MAX) {
                    continue;
                }
                ans = min(ans, futureCost + initialCost);
            }
            dp[i] = ans;
        }
        return dp[0];
    }

    ll costToConvert(string& start, string& end, vector<vector<ll>>& cost) {
        if (start == end) {
            return 0;
        }
        if (mp.count(start) == 0 || mp.count(end) == 0) {
            return LLONG_MAX;
        }
        ll startInd = mp[start], endInd = mp[end];
        return cost[startInd][endInd];
    }
    vector<vector<ll>> floydWarshall(const vector<vector<ll>>& graph) {
        ll n = graph.size();
        vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = min(graph[i][j], dist[i][j]);
            }
        }
        for (ll k = 0; k < n; ++k) {
            for (ll i = 0; i < n; ++i) {
                for (ll j = 0; j < n; ++j) {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        return dist;
    }
};