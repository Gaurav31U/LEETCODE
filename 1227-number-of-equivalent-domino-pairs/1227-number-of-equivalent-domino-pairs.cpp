class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i][0]>dominoes[i][1])swap(dominoes[i][0],dominoes[i][1]);
        }
        map<vector<int>,int> mp;
        for(auto it:dominoes)mp[it]++;
        int ans=0;
        for(auto it:mp)ans+=((it.second*(it.second-1))/2);
        return ans;
    }
};