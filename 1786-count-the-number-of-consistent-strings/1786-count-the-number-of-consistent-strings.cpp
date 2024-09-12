class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=words.size();
        unordered_map<char,int> mp;
        for(auto it:allowed)mp[it]++;
        for(auto it:words){
            for(auto i:it)if(!mp[i]){
                cnt--;
                break;
            }
        }
        return cnt;
    }
};