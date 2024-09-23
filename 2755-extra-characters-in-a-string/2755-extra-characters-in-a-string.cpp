class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mp;
        for(auto it:dictionary)mp[it]++;
        int dp[51];
        memset(dp,-1,sizeof(dp));
        auto get=[&](auto&& get,int i)->int{
            if(i>=s.size())return 0;
            if(dp[i]!=-1)return dp[i];
            string tmp="";
            int ans=INT_MAX/2;
            ans=min(ans,1+get(get,i+1));
            for(int j=i;j<s.size();j++){
                tmp+=s[j];
                if(mp.count(tmp))
                    ans=min(ans,get(get,j+1));
            }

            return dp[i]=ans;
        };
        return get(get,0);
    }
};