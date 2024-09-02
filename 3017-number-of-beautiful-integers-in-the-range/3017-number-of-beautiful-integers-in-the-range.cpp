class Solution {
public:
    int dp[11][21][50][2][2];
    int solve(string& num, int n, int diff, int sum, int k, bool leading, bool tight){
        if(n == 0){
            if(diff==0 && sum == k) return 1;
            else return 0;
        }
        if(dp[n][10+diff][sum][leading][tight] != -1) return dp[n][10+diff][sum][leading][tight];
        int ans = 0;
        int ub = tight ? num[num.size()-n]-'0' : 9;
        for(int dig = 0; dig<=ub; dig++){
            if(dig == 0 && leading == 1){
                ans += solve(num, n-1, diff, (sum%k)+k, k, 1, 0);
            }
            else{
                int val = 1;
                for(int i=0; i<n-1; i++){
                    val *= 10;
                }
                if(dig%2){
                    ans += solve(num, n-1, diff+1, ((sum+(dig*val))%k)+k, k, 0, (tight&(ub==dig)));
                }
                else{
                    ans += solve(num, n-1, diff-1, ((sum+(dig*val))%k)+k, k, 0, (tight&(ub==dig)));
                }
            }
        }
        return dp[n][10+diff][sum][leading][tight] = ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {   
        string l = to_string(low-1);
        string r = to_string(high);
        memset(dp, -1, sizeof(dp));
        int a = solve(l, l.size(), 0, 0, k, 1, 1);
        memset(dp, -1, sizeof(dp));
        int b = solve(r, r.size(), 0, 0, k, 1, 1);
        return b-a;
    }
};