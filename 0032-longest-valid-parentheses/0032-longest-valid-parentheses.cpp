class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++){
            if(s[i]==')' && i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='('){
                dp[i]=2+dp[i-1]+(i-dp[i-1]-2>=0?dp[i-dp[i-1]-2]:0);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,dp[i]);
        return ans;
    }
};