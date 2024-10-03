class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        int c=0,sum=0;
        for(int i=0;i<s.size();i++){
            c++;
            sum+=(s[i]-'a');
            if(c==k){
                ans+=char(sum%26+'a');
                c=0;
                sum=0;
            }
        }
        return ans;
    }
};