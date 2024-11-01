class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        vector<int> v;
        for(auto i:factory){
            int m=i[1];
            while(m--){
                v.push_back(i[0]);
            }
        }
        long long mn=-1e12;
        sort(v.begin(),v.end());
        long long dp[101][v.size()+1];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&&get,int i,int j)->long long{
            if(i>=robot.size())return 0;
            if(j>=v.size())return 1e15;

            if(dp[i][j]!=-1)return dp[i][j];
            long long ans=1e15;

            ans=min(ans,get(get,i,j+1));
            ans=min(ans,abs(robot[i]-v[j])+get(get,i+1,j+1));
            return dp[i][j]=ans;
        };
        return get(get,0,0);
    }
};