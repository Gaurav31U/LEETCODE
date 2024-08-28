class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int solve(int idx,vector<vector<int>>&events,int k){
        if(idx>=n || k==0){
            return 0;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int skip=solve(idx+1,events,k);
        int start=events[idx][0];
        int end=events[idx][1];
        int value=events[idx][2];
        int j=0;
        for( j=idx+1;j<n;j++){
            if(events[j][0]>end){
                break;
            }
        }
        int take=value+solve(j,events,k-1);
        return dp[idx][k]=max(take,skip);

    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return solve(0,events,k);

    }
};