class Solution {
public:
    int findTheLongestSubstring(string s) {
        int tmp=0;
        vector<int> mp(130,0);
        mp['a']=mp['e']=mp['i']=mp['u']=mp['o']=1;
        vector<int> vi;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]])tmp^=(1<<(s[i]-'a'));
            vi.push_back(tmp);
        }
        map<int,int> hash;
        int ans=0;
        hash[0]=0;
        for(int i=0;i<vi.size();i++){
            if(hash.count(vi[i])){
                if(vi[i]==0)
                    ans=max(ans,i-hash[vi[i]]+1);
                else
                    ans=max(ans,i-hash[vi[i]]);
            }else{
                hash[vi[i]]=i;
            }
        }
        return ans;
    }
};