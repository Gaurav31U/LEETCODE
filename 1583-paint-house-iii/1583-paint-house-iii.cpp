class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int mx=1e8;
        int dp[101][101][25];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int k,int c)->int{
            if(k<0)return mx;
            if(i>=houses.size()){
                if(k==0)return 0;
                return mx;
            }
            if(dp[i][k][c+1]!=-1)return dp[i][k][c+1];
            int ans=mx;
            if(houses[i]==0){
                for(int j=0;j<cost[i].size();j++){
                    if(c==(j+1))
                        ans=min(ans,cost[i][j]+get(get,i+1,k,c));
                    else ans=min(ans,cost[i][j]+get(get,i+1,k-1,j+1));
                }
            }else{
                if(houses[i]==c)
                    return dp[i][k][c+1]=get(get,i+1,k,houses[i]);
                else 
                    return dp[i][k][c+1]=get(get,i+1,k-1,houses[i]);
            }
            return dp[i][k][c+1]=ans;
        };
        int ans=get(get,0,target,-1);
        if(ans==mx)return -1;
        return ans;
    }
};