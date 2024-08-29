class node{
    public:
    int cnt,end;
    node* next[26];
    node(){
        cnt=0;
        end=0;
        for(int i=0;i<26;i++)
            next[i]=NULL;
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
            if(temp->next[s[i]-'a']==NULL){
                temp->next[s[i]-'a']=new node;
            }
            temp=temp->next[s[i]-'a'];
            temp->cnt++;
        }
        temp->end=1;
    }
    bool ispresent(string s){
        node* temp=trie;
        for(int i=0;i<s.size();i++){
            if(temp->next[s[i]-'a']==NULL)return false;
            temp=temp->next[s[i]-'a'];
        }
        return true;
    }
    bool ispossible(string s){
        node* temp=trie;
        for(int i=0;i<s.size();i++){
            if(temp->next[s[i]-'a']==NULL)return false;
            temp=temp->next[s[i]-'a'];
        }
        return temp->end==1;
    }
};
class Encrypter {
public:
    map<char,string> mp;
    map<string,vector<char>> dec;
    map<string,int> pos;
    Trie trie;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++){
            mp[keys[i]]=values[i];
            dec[values[i]].push_back(keys[i]);
        }
        for(auto it:dictionary){
            pos[it]++;
            trie.insert(it);
        }
    }
    string encrypt(string word1) {
        string ans="";
        for(auto it:word1){
            if(mp.count(it))ans+=mp[it];
            else return "";
        }
        return ans;
    }
    int decrypt(string word2) {
        int n=word2.size();
        auto get=[&](auto&& get,int i,node* temp)->int{
            if(i>=n){
                return temp->end;
            }
            int ans=0;
            string s=word2.substr(i,2);
            for(auto it:dec[s])
                if(temp->next[it-'a']!=NULL)
                    ans+=get(get,i+2,temp->next[it-'a']);
            return ans;
        };
        return get(get,0,trie.trie);
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */