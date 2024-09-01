class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        map<int,vector<int>> temp;
        set<int,greater<int>> s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                temp[grid[i][j]].push_back(i);
                s.insert(grid[i][j]);
            }
        }
        vector<int> vi;
        for(auto it:s)vi.push_back(it);
        int dp[vi.size()+1][1<<11];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int mask)->int{
            if(i>=vi.size())return 0;
            if(dp[i][mask]!=-1)return dp[i][mask];
            int ans=0;
            auto t=temp[vi[i]];
            for(auto it:t){
                if((mask&(1<<it))==0)
                    ans=max(ans,vi[i]+get(get,i+1,mask|(1<<it)));
            }
            ans=max(ans,get(get,i+1,mask));
            return dp[i][mask]=ans;
        };
        return get(get,0,0);
    }
};