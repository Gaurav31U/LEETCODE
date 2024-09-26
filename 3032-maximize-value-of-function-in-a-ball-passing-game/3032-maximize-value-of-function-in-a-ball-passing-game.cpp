#define ll long long
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& v, long long k) {
        int n = v.size();
        ll ans(-1);
        int ub = log2(k);
        vector<vector<int>> last_receiver(n,vector<int>(ub+1,0));
        vector<vector<ll>> sum(n,vector<ll>(ub+1,0));
        for(int i = 0 ; i < n ; ++i)
        {
            last_receiver[i][0] = v[i];
            sum[i][0] = i;
        }
        for(int j = 1 ; j <= ub ; ++j)
        {
            for(int i = 0 ; i < n ; ++i)
            {
                last_receiver[i][j] = last_receiver[last_receiver[i][j-1]][j-1];
                sum[i][j] = sum[i][j-1] + sum[last_receiver[i][j-1]][j-1]; 
            }
        } 
        for(int i = 0 ; i < n ; ++i)
        {
            ll op(0);
            int x = i;
            for(int j = 0 ; j <= ub ; ++j)
            {
                if((1ll<<j)&k)
                {
                    op += sum[x][j];
                    x = last_receiver[x][j];
                }
            }
            op += x;
            ans = max(ans,op);
        }
        return ans;
    }
}; 