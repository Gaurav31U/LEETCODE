class Solution {
public:
    int minimumDistance(string word) {
        vector<pair<int,int>> temp;
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                temp.push_back({i,j});
            }
        } 
        int dp[26][26];
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                auto a=temp[i];
                auto b=temp[j];
                dp[i][j]=abs(a.first-b.first)+abs(a.second-b.second);
            }
        }
        int dp1[301][27][27];
        memset(dp1,-1,sizeof(dp1));
        auto get=[&](auto&& get,int i,int lastch1,int lastch2)->int{
            if(word.size()<=i)return 0;
            if(dp1[i][lastch1-'A'][lastch2-'A']!=-1)return dp1[i][lastch1-'A'][lastch2-'A'];
            int ans=0;
            ans=dp[word[i]-'A'][lastch1-'A']+get(get,i+1,word[i],lastch2);
            ans=min(ans,dp[word[i]-'A'][lastch2-'A']+get(get,i+1,lastch1,word[i]));
            return dp1[i][lastch1-'A'][lastch2-'A']=ans;
        };
        int ans=INT_MAX;
        for(int i=0;i<word.size();i++){
            for(int j=i+1;j<word.size();j++){
                ans=min(ans,get(get,0,word[i],word[j]));
            }
        }
        return ans;

        
    }
};