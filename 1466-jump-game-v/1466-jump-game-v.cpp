class Solution {
public:
    int dp[1001];
    int help(int i,int d,vector<int>&arr) {
        if(dp[i]!=-1) return dp[i];
        int ans = 1;
        for(int j=i+1;j<min((int)arr.size(),i+d+1);j++) {
            if(arr[j]>=arr[i]) break;
            ans=max(ans,1+help(j,d,arr));
        }
        for(int j=i-1;j>=max(0,i-d);j--) {
            if(arr[j]>=arr[i]) break;
            ans=max(ans,1+help(j,d,arr));
        }
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp,-1,sizeof(dp));
        int mx =1 ;
        for(int i=0;i<arr.size();i++) {
            mx=max(mx,help(i,d,arr));
        }
        return mx;
    }
};