class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int dp[m+1];
        for(int i=0;i<=m;i++){
                dp[i]=1;
        }
        for(int i=0;i<m;i++){
            for(int j=i-1;j>=0;j--){
                int cnt=0;
                for(int k=0;k<n;k++){
                    if(strs[k][i]>=strs[k][j])cnt++;
                }
                if(cnt==n){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)ans=max(ans,dp[i]);
        return m-ans;
    }
};