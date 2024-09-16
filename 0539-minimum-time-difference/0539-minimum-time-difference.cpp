class Solution {
public:
    int time_in_int(string n){
        return 60*stoi(n.substr(0,2))+stoi(n.substr(3));
    }
    int findMinDifference(vector<string>& timePoints) {
        int n=24*60*2+1;
        int dp[n];
        memset(dp,0,sizeof(dp));
        int ans=n;
        for(auto it:timePoints){
            int val=time_in_int(it);
            if(dp[val]>0)return 0;
            dp[val]++;
        }
        for(int i=24*60;i<n;i++){
            dp[i]=dp[i-24*60];
        }
        int j=-1;
        for(int i=0;i<n;i++){
            if(j==-1 && dp[i]){
                j=i;
            }else if(dp[i]){
                ans=min(ans,i-j);
                j=i;
            }

        }
        return ans;

    }
};