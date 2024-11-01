class Solution {
public:
    int maxHeight(vector<vector<int>>& cub) {
        for(auto&i:cub){
            sort(i.begin(),i.end());
        }
        sort(cub.begin(),cub.end());
        int dp[101][102];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int last)->int{
            if(i>=cub.size())return 0;
            if(dp[i][last+1]!=-1)return dp[i][last+1];
            int ans=0;
            if(last==-1){
                for(int j=i;j<cub.size();j++){
                    ans=max(ans,cub[j][2]+get(get,j+1,j));
                }
            }else{
                for(int j=i;j<cub.size();j++){
                    if(cub[last][0]<=cub[j][0] && cub[last][1]<=cub[j][1] && cub[last][2]<=cub[j][2] ){
                        ans=max(ans,cub[j][2]+get(get,j+1,j));
                    }
                }
            }
            return dp[i][last+1]=ans;
        };
        return get(get,0,-1);
    }

};