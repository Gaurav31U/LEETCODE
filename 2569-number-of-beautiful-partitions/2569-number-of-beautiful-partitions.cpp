class Solution {
public:
    int mod=1e9+7;
    int beautifulPartitions(string s, int K, int minLength) {
        vector<int> prime(10,0);
        prime[2]=prime[3]=prime[5]=prime[7]=1;
        int n=s.size();
        if(prime[s[n-1]-'0']==1)return 0;
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int k)->int{
            if(i>=n && k==0)return 1;
            if(i>=n || k<0 || n-i<minLength*k)return 0;
            if(prime[s[i]-'0']==0)return 0;
            if(dp[i][k]!=-1)return dp[i][k];
            long long ans=0;
            for(int j=i+minLength-1;j<n;j++){
                if(prime[s[j]-'0']==0)
                    (ans+=get(get,j+1,k-1))%=mod;
            }
            return dp[i][k]=ans;
        };
        return get(get,0,K);
    }
};