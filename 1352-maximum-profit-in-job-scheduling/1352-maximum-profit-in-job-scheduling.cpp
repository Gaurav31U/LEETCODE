class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int dp[50001];
        memset(dp,-1,sizeof(dp));
        vector<array<int,3>> temp;
        for(int i=0;i<startTime.size();i++){
            temp.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(temp.begin(),temp.end());
        startTime.clear();
        endTime.clear();
        profit.clear();
        for(auto it:temp){
            startTime.push_back(it[0]);
            endTime.push_back(it[1]);
            profit.push_back(it[2]);
        }
        auto get=[&](auto&& get,int i)->int{
            if(i>=startTime.size())return 0;
            if(dp[i]!=-1)return dp[i];
            int ans=0;
            ans=max(ans,get(get,i+1));
            auto it=lower_bound(startTime.begin(),startTime.end(),endTime[i]);
            if(it!=startTime.end()){
                int val=*it;
                while(it!=startTime.end() && *it==val){
                    int idx=it-startTime.begin();
                    if(idx>i)
                    ans=max(ans,profit[i]+get(get,idx));
                    it++;
                }
            }else ans=max(ans,profit[i]);
            return dp[i]=ans;
        };
        return get(get,0);
    }
};