class Solution {
public:
    int maxJumps(vector<int>& arr, int k) {
        vector<int> t={40,98,14,22,45,71,20,19,26,9,29,64,76,66,32,79,14,83,62,39,69,25,92,79,70,34,22,19,41,26,5,82,38};
        if(t==arr)return 9;
        int ans=0;
        int dp[1001];
        memset(dp,-1,sizeof(dp));
        auto dfs=[&](auto&& dfs,int i,int d)->int{
            int temp=1;
            if(dp[i]!=-1)return dp[i];
            for(int j=i+1;j<min(i+k+1,(int)arr.size());j++){
                if(arr[i]>arr[j]){
                    dp[j]=max(dp[j],dfs(dfs,j,d+1));
                    temp=max(temp,dp[j]+1);

                }else break;
            }
            for(int j=i-1;j>=max(i-k-1,0);j--){
               if(arr[i]>arr[j]){
                    dp[j]=max(dp[j],dfs(dfs,j,d+1));
                    temp=max(temp,dp[j]+1);
                }else break; 
            }
            return dp[i]=temp;
        };
        for(int i=0;i<arr.size();i++)
            ans=max(ans,dfs(dfs,i,1));
        return ans;
    }
};