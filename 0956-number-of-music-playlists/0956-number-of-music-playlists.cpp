int n,k;
class Solution {
public:
    const int mod=1e9+7;
    vector<vector<int>> dp;
    int dfs(int i, int j){
        if (i==0 && j==0) return dp[i][j]=1;
        if (i==0 || j==0) return dp[i][j]=0;
        if (dp[i][j]!=INT_MIN) return dp[i][j];
        long long ans=(long long)dfs(i-1, j-1)*(n-j+1)%mod;//new song
        if (j>k)
            ans+=(long long)dfs(i-1, j)*(j-k)%mod;//old song
        return dp[i][j]=ans%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        ::n=n;
        ::k=k;
        dp.assign(goal+1, vector<int>(n+1, INT_MIN));
        return dfs(goal, n);
    }
    
};