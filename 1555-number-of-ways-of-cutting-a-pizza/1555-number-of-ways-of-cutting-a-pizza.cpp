class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int md=1e9+7;
        int n=pizza.size();
        int m=pizza[0].size();
        int dp[51][51][11];
        memset(dp,-1,sizeof(dp));
        vector<vector<int>> pre(vector(n+1, vector(m+1, 0)));

        for (int r = n - 1; r >= 0; r--)
            for (int c = m - 1; c >= 0; c--)
                pre[r][c] = pre[r][c+1] + pre[r+1][c] - pre[r+1][c+1] + (pizza[r][c] == 'A');


        auto get=[&](auto&& get,int i,int j,int p)->int{
            if(pre[i][j]==0)return 0;
            if(p==0)return 1;
            if(dp[i][j][p]!=-1)return dp[i][j][p];
            if(i>=n || j>=m || p<0){
              return 0;
            }
            int ans=0;
            for(int l=i+1;l<n;l++)
              if(pre[i][j]-pre[l][j]>0)
                (ans+=get(get,l,j,p-1))%=md;
              
            for(int l=j+1;l<m;l++)
              if(pre[i][j]-pre[i][l])
                (ans+=get(get,i,l,p-1))%=md;
            return dp[i][j][p]=ans;
        };
        return get(get,0,0,k-1);
    }
};