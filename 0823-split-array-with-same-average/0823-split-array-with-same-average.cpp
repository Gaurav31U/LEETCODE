class Solution {
public:
    bool splitArraySameAverage(vector<int>& a) {
        int n = a.size();
        int sum = accumulate(a.begin(), a.end(), 0);
        vector<int> dp(sum+1,0);
        for(int i=1;i<=n;i++){
            for(int j=sum-a[i-1];j>=0;j--){
                if(dp[j]==0)continue;
                dp[j+a[i-1]]|=dp[j]<<1;
            }
            dp[a[i-1]]|=1;
        }
        for(int len=1; len<n; len++) 
            if( (sum*len)%n == 0 && ((1<<(len-1)) & dp[sum*len/n])) 
                return true;
        return false;
    }
};