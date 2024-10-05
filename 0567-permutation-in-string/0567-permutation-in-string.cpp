 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        if(n>m)return false;
        vector<int> mp1(26,0),mp2(26,0);
        for(auto it:s1)mp1[it-'a']++;
        for(int i=0;i<n;i++){
            mp2[s2[i]-'a']++;
        }
        if(mp1==mp2)return true;
        for(int i=n;i<m;i++){
            mp2[s2[i-n]-'a']--;
            mp2[s2[i]-'a']++;
            if(mp1==mp2)return true;
        }  
        return false;
    }
};