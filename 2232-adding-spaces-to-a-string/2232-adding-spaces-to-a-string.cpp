class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        unordered_map<int,int> mp;
        for(auto it:spaces)mp[it]++;
        for(int i=0;i<s.size();i++){
            if(mp.find(i)!=mp.end()){
                ans+=' ';
            }
            ans+=s[i];
        }
        return ans;
    }
};