class Solution {
public:
    int mx=1e5;
    int dp[501][501];
    int getans(int i,int j,string &s){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=mx;
        if(s[i]==s[j])return getans(i+1,j-1,s);
        ans=min(ans,getans(i+1,j,s)+1);
        ans=min(ans,getans(i,j-1,s)+1);
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return getans(0,s.size()-1,s);
    }
};