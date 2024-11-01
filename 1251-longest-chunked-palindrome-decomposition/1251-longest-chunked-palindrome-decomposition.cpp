class Solution {
public: 
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int longestDecomposition(string text) {
        int ans=0;
        while(1){
            if(text[0]==text.back()){
                if(text.size()==1){ans++;break;}
                if(text.size()==2){ans+=2;break;}
                ans+=2;
                text.pop_back();
                text=text.substr(1);
                continue;
            }
            auto temp=prefix_function(text);
            int val=temp.back();
            if(val==0){
                ans++;
                break;
            }
            ans+=2;
            while(val>0){
                text.pop_back();
                val--;
            }
            text=text.substr(temp.back());
            if(text.empty())break;
        }
        return ans;
    }
};