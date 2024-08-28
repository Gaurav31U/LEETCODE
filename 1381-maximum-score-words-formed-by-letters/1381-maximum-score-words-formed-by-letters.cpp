class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n=words.size();
        vector<int> freq(128,0);
        for(auto it:letters){
            freq[it]++;
        } 
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            bool found=true;
            int s=0;
            auto f=freq;
            for(int j=0;j<n;j++){   
                if(i&(1<<j)){
                    for(auto it:words[j]){
                        f[it]--;
                        s+=score[it-'a'];
                        if(f[it]<0){
                            found=false;
                        }
                    }
                }
                if(!found)break;
            }
            if(found)ans=max(s,ans);
        }
        return ans;
    }
};