class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int dp[102][102];
        memset(dp,-1,sizeof(dp));
        vector<int> temp;
        int pre=0;
        for(int i=0;i<cuts.size();i++){
          temp.push_back(cuts[i]-pre);
          pre=cuts[i];
        } 
        temp.push_back(n-pre);
        for(auto it:temp)cout<<it<<" ";
        auto arr=temp;
        for(int i=1;i<temp.size();i++){
          temp[i]+=temp[i-1];
        }
        auto get=[&](auto&& get,int i,int j)->int{
          if(i>=j)return 0;
          if(dp[i][j]!=-1)return dp[i][j];
          int ans=INT_MAX;
          for(int k=i;k<j;k++){
            int val=temp[j]-(i>0?temp[i-1]:0);
            ans=min(ans,get(get,i,k)+get(get,k+1,j)+val);
          }
          return dp[i][j]=ans;
        };

      return get(get,0,temp.size()-1);

    }
};