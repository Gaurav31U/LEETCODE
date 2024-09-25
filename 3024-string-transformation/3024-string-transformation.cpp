struct StringAlgorithm {
    static std::vector<int> kmp(const std::string& s, const std::string& t) {
        int m = s.size(), n = t.size();
        std::vector<int> pi(n, 0), res;
        for (int i = 1; i < n; ++i) {
            int j = pi[i - 1];
            while (j > 0 && t[j] != t[i]) j = pi[j - 1];
            if (j == 0 && t[0] != t[i]) pi[i] = 0;
            else pi[i] = j + 1;
        }
        int j = 0;
        for (int i = 0; i < m; ++i) {
            while (j >= n || (j > 0 && s[i] != t[j])) j = pi[j - 1];
            if (s[i] == t[j]) j++;
            if (j == n) res.push_back(i - n + 1);
        }
        return res;
    }    
};
class Solution {
public:
    long long pow(long long a, long long b, const long long M) {
        if (b == 0) return 1;
        if ((b & 1) == 0) return pow(a * a % M, b >> 1, M);
        return a * pow(a * a % M, b >> 1, M) % M;
    }
    int numberOfWays(string s, string t, long long k) {
        long long n = s.size(), M = 1e9 + 7;
        auto pos = StringAlgorithm::kmp(s + s.substr(0, n-1), t);
        long long f_k[2];
        f_k[1] = (pow(n-1, k, M) + (k % 2 * 2 - 1) + M) % M * pow(n, M-2, M) % M;
        f_k[0] = (f_k[1] - (k % 2 * 2 - 1) + M) % M;
        return accumulate(pos.begin(), pos.end(), 0ll, 
            [&](long long s, long long p) { return (s + f_k[!!p]) % M; } );
    }
};