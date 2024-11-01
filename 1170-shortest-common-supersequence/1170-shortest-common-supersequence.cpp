class Solution {
public:
    int dp[1001][1001];
    int getans(int i,int j,string &s1,string &s2){
        if(i==0 || j==0)return dp[i][j]=0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s1[i-1]==s2[j-1]){
            ans=max(ans,1+getans(i-1,j-1,s1,s2));
        }
        ans=max(ans,getans(i-1,j,s1,s2));
        ans=max(ans,getans(i,j-1,s1,s2));
        return dp[i][j]=ans;

    }
    string shortestCommonSupersequence(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        getans(s1.size(),s2.size(),s1,s2);
        dp[0][0]=0;
        string ans="";
        int i=s1.size();
        int j=s2.size();
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--;j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                ans+=s1[i-1];
                i--;
            }else{
                ans+=s2[j-1];
                j--;
            }
        }
        i--,j--;
        while(i>=0)ans+=s1[i--];
        while(j>=0)ans+=s2[j--];
        reverse(ans.begin(),ans.end());
        return ans;
    }
};