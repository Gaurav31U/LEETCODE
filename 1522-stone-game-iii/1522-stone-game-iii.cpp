class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
        int n=stone.size();
        int dp[n+1][2];
        for(int i=0;i<=n;i++)dp[i][0]=dp[i][1]=INT_MIN;
        auto get=[&](auto&& get,int i,int turn)->int{
            if(i>=n)return 0;
            if(dp[i][turn]!=INT_MIN)return dp[i][turn];
            int ans=0;
            if(turn){
                ans=INT_MIN;
                int s=0;
                for(int j=i;j<min(n,i+3);j++){
                    s+=stone[j];
                    ans=max(ans,s+get(get,j+1,turn^1));
                }
            }else{  
                ans=INT_MAX;
                int s=0;
                for(int j=i;j<min(n,i+3);j++){
                    s+=stone[j];
                    ans=min(ans,get(get,j+1,turn^1)-s);
                }
            }
            return dp[i][turn]=ans;
        };
        int ans=get(get,0,1);
        if(ans>0)return "Alice";
        if(ans==0)return "Tie";
        return "Bob";
    }
};