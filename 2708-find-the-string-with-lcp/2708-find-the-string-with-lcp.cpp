class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,'*');
        ans[0]='a';
        char mn='b';
        for(int i=1;i<n;i++){
            bool found=true;
            for(int j=0;j<i;j++){
                if(lcp[i][j]!=0){
                    ans[i]=ans[j];
                    found=false;
                    break;
                }
            }
            if(found)ans[i]=mn++;
        }
        for(int i=0;i<n;i++)if(ans[i]>'z')return "";
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(ans[i]==ans[j]){
                    dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
                }
                if(dp[i][j]!=lcp[i][j])return "";
            }
        }
        return ans;
    }
};