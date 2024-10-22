class Solution {
public:
    int countVowelPermutation(int n) {
        //a-0 e-1 i-2 o-3 u-4
       long long dp[n+1][5];
        int md=1e9+7;
        memset(dp,0,sizeof(dp));
        dp[1][0]=1,dp[1][1]=1,dp[1][2]=1,dp[1][3]=1,dp[1][4]=1;
        for(int i=2;i<=n;i++){
            (dp[i][0]+=(dp[i-1][1]+dp[i-1][4]+dp[i-1][2]))%=md;
            (dp[i][1]+=(dp[i-1][0]+dp[i-1][2]))%=md;
            (dp[i][2]+=(dp[i-1][1]+dp[i-1][3]))%=md;
            (dp[i][3]+=(dp[i-1][2]))%=md;
            (dp[i][4]+=(dp[i-1][3]+dp[i-1][2]))%=md;
        }
        int ans=0;
        for(int i=0;i<5;i++)
            (ans+=dp[n][i])%=md;
        return ans;
    }
};