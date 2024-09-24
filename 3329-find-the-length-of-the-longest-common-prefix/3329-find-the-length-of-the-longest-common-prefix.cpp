class node{
    public:
    int cnt;
    node* next[11];
    node(){
        cnt=0;
        for(int i=0;i<=10;i++)next[i]=NULL;
    }
};
class Trie{
    public:
    node* trie;
    Trie(){
        trie=new node;
    }
    void insert(string s){
        node* tmp=trie;
        for(int i=0;i<s.size();i++){
            if(tmp->next[s[i]-'0']==NULL){
                tmp->next[s[i]-'0']=new node;
            }
            tmp=tmp->next[s[i]-'0'];
        }
    }
    int findmax(string s){
        node* tmp=trie;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(tmp->next[s[i]-'0']==NULL)return ans;
            tmp=tmp->next[s[i]-'0'];
            ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(auto it:arr2){
            trie.insert(to_string(it));
        }
        int ans=0;
        for(auto it:arr1){
            ans=max(ans,trie.findmax(to_string(it)));
        }
        return ans;
    }
};