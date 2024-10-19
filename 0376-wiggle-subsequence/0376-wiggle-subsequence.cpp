class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int dp[1001][1002][3];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i,int last,int seq)->int{
            if(i>=n)return 0;
            if(dp[i][last+1][seq+1]!=-1)return dp[i][last+1][seq+1];
            int ans=0;
            if(last!=-1){
                if(nums[last]-nums[i]>0){
                    if(seq==-1){
                        ans=max(ans,get(get,i+1,i,1)+1);
                        ans=max(ans,get(get,i+1,last,-1));
                    }else if(seq==1){
                        ans=max(ans,get(get,i+1,last,1));
                    }else{
                        ans=max(ans,get(get,i+1,i,1)+1);
                        ans=max(ans,get(get,i+1,last,seq));
                    }
                }else if(nums[last]-nums[i]<0){
                    if(seq==-1){
                        ans=max(ans,get(get,i+1,i,0)+1);
                        ans=max(ans,get(get,i+1,last,-1));
                    }else if(seq==1){
                        ans=max(ans,get(get,i+1,i,0)+1);
                        ans=max(ans,get(get,i+1,last,seq));
                    }else{
                        ans=max(ans,get(get,i+1,last,seq));
                    }
                }
            }else{
                ans=max(ans,get(get,i+1,i,seq)+1);
                ans=max(ans,get(get,i+1,last,seq));
            }
            return dp[i][last+1][seq+1]=ans;
        };
        return get(get,0,-1,-1);
    }
};