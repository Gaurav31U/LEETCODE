constexpr int m = 100000;
long long fact[m + 1], inv_fact[m + 1], mod = 1000000007, init = 0;
class Solution {
public:
    int modPow(int x, int y, int mod){
        if (y == 0)
            return 1;
        long p = modPow(x, y / 2, mod) % mod;
        p = (p * p) % mod;
        return y % 2 ? (p * x) % mod : p;
    }
    long long binom_coeff(int n, int k) {
        return max(1LL, fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod);
    }
    int numberOfSequence(int n, vector<int>& sick) {
        if (!init) {
            init = fact[0] = 1;
            for (int i = 1; i <= m; ++i)
                fact[i] = fact[i - 1] * i % mod;
            inv_fact[m] = modPow(fact[m], mod - 2, mod);
            for (int i = m - 1; i; --i)
                inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
        }
        long long res = 1;
        for (int i = 1; i < sick.size(); ++i) {
            int group = sick[i] - sick[i - 1] - 1;
            res = res * modPow(2, max(0, group - 1), mod) % mod; // combine
            res = res * binom_coeff(sick[i] - i, group) % mod; // interweave
        }
        return res * binom_coeff(n - sick.size(), n - sick.back() - 1) % mod;
    }
};