class node{
    public:
    int valid;
    int cnt;
    node* next[26];
    node(){
        valid=0;
        cnt=0;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
};
class Trie{
    public:
    node* trie;
    Trie(){
        trie=new node;
    }
    vector<int> z_function(string s){
        int n=s.size();
        vector<int> z(n,0);
        for(int i=1,l=0,r=0;i<n;i++){
            if(r>=i){
                z[i]=min(z[i-l],r-i+1);
            }
            while(z[i]+i<n && s[z[i]]==s[z[i]+i]){
                z[i]++;
            }
            if(i+z[i]-1>r){
                r=i+z[i]-1;
                l=i;
            }
        }
        return z;
    }
    void insert(string s){
        int n=s.size();
        auto z=z_function(s);
        node* temp=trie;
        for(int i=0;i<s.size();i++){
            if(temp->next[s[i]-'a']==NULL){
                temp->next[s[i]-'a']=new node;
            }
            temp=temp->next[s[i]-'a'];
            int l=i+1;
            int val=z[n-i-1];
            if(l==val){
                temp->valid=1;
                temp->cnt++;
            }
        }
        // if(n==1){
        //     temp->valid=1;
        //     temp->cnt++;
        // }
    }
    int findans(string s){
        node* temp=trie;
        for(int i=0;i<s.size();i++){
            if(temp->next[s[i]-'a']==NULL)return 0;
            temp=temp->next[s[i]-'a'];
        }
        return temp->cnt;
    }
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans=0;
        Trie trie;
        int n=words.size();
        unordered_map<string,long long> mp;
        for(int i=n-1;i>=0;i--){
            mp[words[i]]++;
            int val=trie.findans(words[i]);
            ans+=val;
            trie.insert(words[i]);
        }
        for(auto it:mp){
            ans+=(it.second*(it.second-1)/2);
        }
        return ans;
    }
};