class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size())swap(s1,s2);
        vector<string> v1,v2;
        for(int i=0;i<s1.size();i++){
            string temp="";
            while(i<s1.size() && s1[i]!=' '){
                temp+=s1[i];
                i++;
            }
            v1.push_back(temp);
        }
        for(int i=0;i<s2.size();i++){
            string temp="";
            while(i<s2.size() && s2[i]!=' '){
                temp+=s2[i];
                i++;
            }
            v2.push_back(temp);
        }
        while(!v1.empty() && !v2.empty()){
            if(v1.back()==v2.back()){
                v1.pop_back();
                v2.pop_back();
            }else break;
        }
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        while(!v1.empty() && !v2.empty()){
            if(v1.back()==v2.back()){
                v1.pop_back();
                v2.pop_back();
            }else break;
        }

        return v2.empty();

        
    }
};