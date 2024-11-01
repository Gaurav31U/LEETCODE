class Solution {
public:
    bool winnerSquareGame(int n) {
        double k=sqrt(n);
        if(ceil(k)==floor(k))return true;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        vector<int> temp;
        for(int i=1;i*i<n;i++)temp.push_back(i*i);
        for(int i=1;i<=n;i++){
            for(auto it:temp){
                if(it<=i){
                    if(!dp[i-it])dp[i]=1;
                }else break;
            }
        }
        return dp[n];
    }
};