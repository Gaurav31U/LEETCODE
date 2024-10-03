class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<vector<int>> tmp(n,vector<int>(k+1,1));
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                tmp[i][j]=(tmp[i-1][j]+tmp[i][j-1])%mod;
            }
        }
        return tmp[n-1][k];
    }
};