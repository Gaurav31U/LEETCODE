class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string,int> tmp;
        for(int i=0;i<s1.size();){
            string t="";
            while(i<s1.size() && s1[i]!=' '){
                t+=s1[i];
                i++;
            }
            tmp[t]++;
            if(s1[i]==' ')i++;
        }
        for(int i=0;i<s2.size();){
            string t="";
            while(i<s2.size() && s2[i]!=' '){
                t+=s2[i];
                i++;
            }
            tmp[t]++;
            if(s2[i]==' ')i++;
        }
        for(auto it:tmp)if(it.second==1)ans.push_back(it.first);
        return ans;
    }
};