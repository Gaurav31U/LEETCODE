class Solution {
public:
    unsigned long long binomialCoefficient(int n, int r) {
        if (r > n) {
            return 0;  
        }
        if (r == 0 || r == n) {
            return 1;  
        }
        r = min(r, n - r); 
        unsigned long long result = 1;
        for (int i = 1; i <= r; ++i) {
            result = result * (n - r + i) / i;
        }
        return result;
    }
    int waysToReachStair(int k) {
        if( k == 0 ) return 2;
        if( k == 1 ) return 4;
        if( k == 2 ) return 4;
        int bit = __builtin_popcount(k);
        int count = 0;
        int l = ceil(log2(k+1));
        int u = 1LL<<l;
        int n = l + 1;
        int r = u - k;
        int ans = binomialCoefficient(n,r)  ;
        return ans + ( bit == 1 ? 1 : 0 ) ;
    }
};