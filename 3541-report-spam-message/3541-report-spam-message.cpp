class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> mp;
        for(auto it:bannedWords)mp[it]++;
        int cnt=0;
        for(auto it:message){
            if(mp.count(it))cnt++;
        }
        return bool(cnt>=2);
    }
};