class Solution {
public:
    int numberOfStableArrays(int z, int o, int l) {
        int mod=1e9+7;
        int dp[z+1][o+1][2];
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=1;
        unordered_map<long long,long long> Z,O;
        Z[0]++,O[0]++;
        for(int i=0;i<=z;i++){
            for(int j=0;j<=o;j++){
                if(i==0&&j==0)continue;
                if(j-l-1>=0){
                    O[i]=(O[i]%mod - dp[i][j-l-1][0]%mod+mod)%mod;
                    O[i]+=mod;
                }
                if(i-l-1>=0){
                    Z[j]=(Z[j]%mod - dp[i-l-1][j][1]%mod+mod)%mod;
                    Z[j]+=mod;
                }
                dp[i][j][0]=Z[j]%mod;
                dp[i][j][1]=O[i]%mod;
                O[i]=(O[i] + dp[i][j][0])%mod;
                Z[j]=(Z[j] + dp[i][j][1])%mod;
            }
        }
        return (dp[z][o][1]+dp[z][o][0])%mod;
    }
};