class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0)return 0;
        int dp[32];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=3;
        dp[2]=7;
        for(int i=3;i<30;i++){
            dp[i]+=2*dp[i-1];
            dp[i]++;
        }
        int ans=0;
        bool ok=true;
        for(int i=0;i<30;i++){
            if((1<<i)&n){
                if(ok)ans-=(dp[i]);
                else ans+=dp[i];
                ok^=1;
            }
        }
        return abs(ans);


    }
};