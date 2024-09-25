class node{
    public:
    int cnt;
    node* next[26];
    node(){
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
    void insert(string s){
        node* temp=trie;
        for(int i=0;i<s.size();i++){
            int t=s[i]-'a';
            if(temp->next[t]==NULL){
                temp->next[t]=new node();
            }
            temp->next[t]->cnt++;
            temp=temp->next[t];
        }
    }
    int findprefix(string s){
        int ans=0;
        node* temp=trie;
        for(int i=0;i<s.size();i++){
            int t=s[i]-'a';
            if(temp->next[t]!=NULL){
                ans+=temp->next[t]->cnt;
                temp=temp->next[t];
            }else break;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie temp;
        for(auto it:words){
            temp.insert(it);
        }
        vector<int> ans;
        for(auto it:words){
            ans.push_back(temp.findprefix(it));
        }
        return ans;
    }
};