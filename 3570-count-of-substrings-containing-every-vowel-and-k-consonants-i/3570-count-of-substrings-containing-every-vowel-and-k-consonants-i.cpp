class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int ans=0;
        string t="aeiou";
        vector<int> tmp(128,0);
        int n=word.size();
        int hash=0;
        for(int i=0;i<t.size();i++){
            tmp[t[i]]=1;
            hash|=(1<<(t[i]-'a'));
        }
        for(int i=0;i<n;i++){
            int cnt=0,mask=0;
            for(int j=i;j<n;j++){
                if(tmp[word[j]]){
                    mask|=(1<<(word[j]-'a'));
                }else cnt++;
                if(cnt==k && mask==hash)ans++;
            }
        }
        return ans;
    }
};