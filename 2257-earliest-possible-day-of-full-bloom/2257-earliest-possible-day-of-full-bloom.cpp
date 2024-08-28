class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans=0;
        vector<pair<int,int>> temp;
        for(int i=0;i<plantTime.size();i++){
            temp.push_back({plantTime[i],growTime[i]});
        }
        sort(temp.begin(),temp.end(),[&](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        });
        int t=0;
        for(auto it:temp){
            t+=it.first;
            ans=max(ans,t+it.second);
        }
        return ans;
    }
};