class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0;i<piles.size();i++){
            for(int j=1;j<piles[i].size();j++){
                piles[i][j]+=piles[i][j-1];
            }
        }
        int n=piles.size();
        int dp[1001][2001];
        memset(dp,-1,sizeof(dp));
        auto getans=[&](auto&& getans,int i,int p)->int{
            if(p==0)return 0;
            if(p<0)return INT_MIN;
            if(i>=n && p==0)return 0;
            if(i>=n)return INT_MIN;
            if(dp[i][p]!=-1)return dp[i][p];
            int ans=getans(getans,i+1,p);
            for(int j=0;j<piles[i].size();j++){
                if(j+1<=k)
                ans=max(ans,piles[i][j]+getans(getans,i+1,p-j-1));
            }
            return dp[i][p]=ans;
        };
        return getans(getans,0,k);
    }
};