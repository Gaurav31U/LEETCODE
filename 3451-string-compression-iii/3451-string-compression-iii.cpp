class Solution {
public:
    string compressedString(string word) {
        string ans="";
        for(int i=0;i<word.size();){
            int cnt=0;
            int e=word[i];
            while(i<word.size() && e==word[i]){
                cnt++;
                i++;
                if(cnt==9)break;
            }
            ans+=to_string(cnt);
            ans+=char(e);
        }
        return ans;
    }
};