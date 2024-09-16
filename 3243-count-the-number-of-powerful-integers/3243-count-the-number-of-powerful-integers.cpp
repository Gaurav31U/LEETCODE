using ll = long long;
class Solution {
public:
    ll pw(ll a, ll b) {
        ll ans = 1;
        while (b--) ans *= a;
        return ans;
    }
    ll get(ll n, ll l, string &s) {
        string N = to_string(n);
        ll ans = 0;
        if (N.size() < s.size()) {
            return 0;
        } else if (N.size() > s.size()) {
            bool ok = 1; 
            for (int i = 0; i < N.size() - s.size(); i++) {
                ok &= ((N[i] - '0') <= l);
                ll cur = min(l + 1, ll(N[i] - '0'));
                if (i == (N.size() - s.size() - 1LL))
                    cur += ok && (N.substr(N.size() - s.size(), s.size()) >= s);
                for (int j = i + 1; j < N.size() - s.size(); j++)
                    cur *= l + 1;
                ans += cur;
                if ((N[i] - '0') > l) break;
            }
        } else {
            ans += N >= s; 
        }
        return ans;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return get(finish, limit, s) - get(start - 1, limit, s);
    }
};