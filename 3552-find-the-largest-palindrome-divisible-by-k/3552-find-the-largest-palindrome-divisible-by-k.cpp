class Solution {
    vector<int> powers;
    vector<vector<int>> dp;
    vector<vector<int>> track;
    
    int rec(int i, int div, int &n, int &k) {
        int mid = (n - 1) / 2;
        if (i > mid) return div == 0;
        
        if (dp[i][div] != -1) return dp[i][div];
        
        for (int j = 9; j >= 0; j--) {
            int add = 0;
            if (i == mid && (n & 1)) {
                add = (j * powers[n - i - 1]) % k;
            } else {
                add = (j * powers[n - i - 1]) % k;
                add = (add + (j * powers[i])) % k;
            }
            if (rec(i + 1, (div + add) % k, n, k)) {
                track[i][div] = j;
                return dp[i][div] = true;
            }
        }
        return dp[i][div] = false;
    }

public:
    string largestPalindrome(int n, int k) {
        dp.assign(n, vector<int>(k, -1));
        track.assign(n, vector<int>(k, -1));
        
        powers.resize(n);
        powers[0] = 1 % k;
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i-1] * 10) % k;
        }
        
        rec(0, 0, n, k);
        string res;
        int div = 0;
        for (int i = 0; i < (n + 1) / 2; i++) {
            res += (track[i][div] + '0');
            int j = track[i][div];
            
            int add = 0;
            if (i == (n - 1) / 2 && (n & 1)) {
                add = (j * powers[n - i - 1]) % k;
            } else {
                add = (j * powers[n - i - 1]) % k;
                add = (add + (j * powers[i])) % k;
            }
            
            div = (div + add) % k;
        }
        string temp = res.substr(0, n / 2);
        reverse(begin(temp), end(temp));
        res += temp;
        return res;
    }
};