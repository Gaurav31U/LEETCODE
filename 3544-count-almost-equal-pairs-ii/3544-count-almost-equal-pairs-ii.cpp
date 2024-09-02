class Solution {
public:
    int countPairs(vector<int>& nums) {
       map<string,int> mp;
       int ans=0;
       int mx=0;
       sort(nums.begin(),nums.end());
       for(auto it:nums){
        string s=to_string(it);
        mx=max(mx,(int)s.size());
       }
       for(int i=0;i<nums.size();i++){
            string p(mx,'0');
            string k=to_string(nums[i]);
            string s=p.substr(k.size())+k;
            if(s.size()==1){
                ans+=mp[s];
            }else if(s.size()<=2){
                ans+=mp[s];
                auto er=s;
                swap(s[0],s[1]);
                if(er!=s)ans+=mp[s];
                
            }else{
                unordered_set<string> st;
                auto t=s;
                for(int j=0;j<s.size();j++){
                    for(int k=j+1;k<s.size();k++){
                        swap(t[j],t[k]);
                        st.insert(t);
                        for(int a=0;a<s.size();a++){
                            for(int b=a+1;b<s.size();b++){
                                if(t[a]!=t[b]){
                                    swap(t[a],t[b]);
                                    st.insert(t);
                                    swap(t[a],t[b]);
                                }
                            }
                        }
                        swap(t[j],t[k]);
                    }
                }
                for(auto it:st){
                    ans+=mp[it];
                }
            }
            mp[s]++;

       } 
       return ans;
    }
};