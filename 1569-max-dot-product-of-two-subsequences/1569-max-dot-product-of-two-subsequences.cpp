class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int mn=-1e7;
        int dp[501][501][2];
        for(int i=0;i<=500;i++)for(int j=0;j<=500;j++)for(int k=0;k<2;k++)dp[i][j][k]=mn;
        int n=nums1.size();
        int m=nums2.size();
        auto get=[&](auto&& get,int i,int j,int ok=0)->int{
            if(i>=n || j>=m){
                if(ok)return 0;
                return mn;
            }
            if(dp[i][j][ok]!=mn)return dp[i][j][ok];
            int ans=mn;
            ans=max(ans,get(get,i+1,j,ok));
            ans=max(ans,get(get,i,j+1,ok));
            ans=max(ans,get(get,i+1,j+1,1)+nums1[i]*nums2[j]);
            return dp[i][j][ok]=ans;
        };
        int t=get(get,0,0);
        return t;
    }
};