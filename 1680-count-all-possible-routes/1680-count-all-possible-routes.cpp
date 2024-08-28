class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int dp[102][201];
        memset(dp,-1,sizeof(dp));
        int md=1e9+7;
        bool found=false;
        auto get=[&](auto&& get,int i,int f)->int{
            if(f<0)return 0;
            if(dp[i][f]!=-1)return dp[i][f];
            int ans=0;
            if(i==finish)ans++;
            for(int j=0;j<locations.size();j++){
                if(locations[j]!=locations[i]){
                    (ans+=get(get, j , f-abs(locations[j]-locations[i]) ) )%=md;
                }
            }
            return dp[i][f]=ans;
        };
        return get(get,start,fuel);
    }
};