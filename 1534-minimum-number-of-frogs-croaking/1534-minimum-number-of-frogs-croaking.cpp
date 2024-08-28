class Solution {
public:
    int minNumberOfFrogs(string s) {
        unordered_map<int,int> mp;
        for(auto it:s)mp[it]++;
        string temp="croak";
        unordered_map<int,int> idx;
        idx['c']=0;
        idx['r']=1;
        idx['o']=2;
        idx['a']=3;
        idx['k']=4;
        set<int> st;
        for(auto it:mp)st.insert(it.second);
        if(st.size()>1)return -1;
        mp.clear();
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(s[i]!='c'){
                mp[temp[idx[s[i]]-1]]--;
                if(mp[temp[idx[s[i]]-1]]<0)return -1;
            }
        }
        int ans=0;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='k')c--;
            if(s[i]=='c')c++;
            ans=max(ans,c);
        }
        return ans;
    }
};