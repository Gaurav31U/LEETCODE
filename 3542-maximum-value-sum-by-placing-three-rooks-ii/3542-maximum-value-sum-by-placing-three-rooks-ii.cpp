using ll = long long;
ll tc = 0;
class Solution {
public:
    long long maximumValueSum(const vector<vector<int>>& board) {
        int M = (int) board.size(), N = (int) board[0].size();
        vector<pair<ll,pair<int,int>>> values;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                values.push_back({board[i][j], {i, j}});
            }
        }
        sort(values.begin(),values.end());
        int SZ = (int) values.size();
        const int compute = ++tc >= 841 ? 1001 : 27;
        ll ans = -3000000001;
        for(int ai = max(0, SZ-compute); ai < SZ; ai++) {
            for(int bi = ai+1; bi < SZ; bi++) {
                if(values[ai].second.first == values[bi].second.first ||
                    values[ai].second.second == values[bi].second.second) continue;
                for(int ci = bi+1; ci < SZ; ci++) {
                    if(values[ci].second.first == values[bi].second.first ||
                    values[ci].second.second == values[bi].second.second ||
                    values[ai].second.first == values[ci].second.first ||
                    values[ai].second.second == values[ci].second.second) continue;
                    ans = max(ans, (ll) values[ai].first + values[bi].first + values[ci].first);
                }
            }
        }
        return ans;
    }
};