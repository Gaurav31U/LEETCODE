class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            map<int,int> mp;
            bool found=false;
            for(int j=i;j<s.size();j++){
                if(++mp[s[j]]>=k)found=true;
                if(found)ans++;
            }
        }
        return ans;
    }
};