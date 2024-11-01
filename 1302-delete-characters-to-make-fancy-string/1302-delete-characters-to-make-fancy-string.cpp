class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int c=0,ch='0';
        for(int i=0;i<s.size();i++){
            if(ch==s[i])c++;
            else ch=s[i],c=1;
            if(c<=2)ans+=s[i];
        }
        return ans;
    }
};