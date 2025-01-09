class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(int i=0;i<words.size();i++){
            bool found=true;
            for(int j=0;j<pref.size();j++){
                if(j>words[i].size() || pref[j]!=words[i][j])found=false;
            }
            if(found)cnt++;
        }
        return cnt;
    }
    
};