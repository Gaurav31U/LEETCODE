class Solution {
public:
    int dp[1001][52];
    vector<int> temp;
    int getans(int i,int m,vector<int> &ar){
        if(dp[i][m]!=-1)return dp[i][m];
        if(m==1)return temp.back()-temp[i];
        int res=INT_MAX,curr=0;
        for(int k=i;k<ar.size();k++){
            curr+=ar[k];
            res=min(res,max(curr,getans(k+1,m-1,ar)));
            if(res<curr)break;
        }
        return dp[i][m]=res;
    }
    int splitArray(vector<int>& nums, int k) {
        temp.clear();
        temp.push_back(0);
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)temp.push_back(temp.back()+nums[i]);
        memset(dp,-1,sizeof(dp));
        return getans(0,k,nums);
    }
};