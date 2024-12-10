class Solution {
public:
    int maximumLength(string s) {
        int ans=-1;
        const string_view tmp(s);
        for(int i=1;i<=s.size();i++){
            for(int j='a';j<='z';j++){
                string a="";
                for(int k=1;k<=i;k++)a+=char(j);
                int cnt=0;
                const string_view p(a);
                for(int k=0;k<s.size();k++){
                    if(tmp.substr(k,i)==p){
                        cnt++;
                    }
                }
                if(cnt>=3)ans=max(ans,i);
            }
        }
        return ans;
    }
};