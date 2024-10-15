class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        vector<int> pre;
        pre.push_back(floor[0]=='1');
        for(int i=1;i<floor.size();i++){
            pre.push_back(pre.back()+(floor[i]=='1'));
        }
        int cnt=pre.back();
        int m=floor.size();
        auto solve=[&](auto&& solve,int i,int n)->int{
            if(i>=m || n<=0)return 0;
            int j=i+carpetLen-1;
            if(j>=m)return pre.back()-(i>0?pre[i-1]:0);
            if(dp[i][n]!=-1)return dp[i][n];
            int ans=0;
            int s=pre[j]-(i>0?pre[i-1]:0);
            ans=max(ans,s+solve(solve,j+1,n-1));
            ans=max(ans,solve(solve,i+1,n));
            return dp[i][n]=ans;
        };
        return cnt-solve(solve,0,numCarpets);
    }
};