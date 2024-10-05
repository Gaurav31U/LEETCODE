class Solution {
public:
    int mod=1e9+7;
    int mx;
    long long dp[301][401];
    long long solve(int i,int cnt,int n,map<int,int>&mp){
        if(i==n)return 1;
        if(dp[i][cnt]!=-1)return dp[i][cnt];
        long long ans=0;
        for(int j=0;j<=i+1;j++){
            long long tmp=cnt+(i-j+1);
            if(tmp<=mx && (!mp.count(i+1) || tmp==mp[i+1]))
                (ans+=(solve(i+1,tmp,n,mp)))%=mod;
        }
        return dp[i][cnt]=ans%mod;

    }
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        map<int,int> mp;
        for(auto it:requirements){
            mp[it[0]]=it[1];
            mx=max(it[1],mx);
        }
        if(mp[0]>0)return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,mp);
    }
};