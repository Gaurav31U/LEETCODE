class Solution {
public:
    class Trie{
    public:
        class node{
            public:
                int end;
                node* next[26];
            node(){
                end=-1;
                for(int i=0;i<26;i++){
                    next[i]=NULL;
                }
            }
        };
        node* trie;
        Trie(){
            trie=new node;
        }
        void insert(string s,int idx){
            int i=0;
            auto it=trie;
            while(i<s.size()){
                if(it->next[s[i]-'a']==NULL){
                    it->next[s[i]-'a']=new node;
                }
                it=it->next[s[i]-'a'];
                i++;
            }
            it->end=idx;
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie temp;
        for(int i=0;i<words.size();i++){
            temp.insert(words[i],i);
        }
        int n=board.size(),m=board[0].size();
        vector<string> ans;
        unordered_map<int,int> mp;
        int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
        int vis[15][15];
        memset(vis,0,sizeof(vis));
        auto dfs=[&](auto&& dfs,int i,int j,Trie::node* val)->void{
            // vis[i][j]=1;
            if(val->end!=-1 && mp.find(val->end)==mp.end()){
                ans.push_back(words[val->end]);
                mp[val->end]++;
            }
            for(int k=0;k<4;k++){
                int ni=dx[k]+i,nj=dy[k]+j;
                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    if(val->next[board[ni][nj]-'a']!=NULL && vis[ni][nj]==0){
                        vis[ni][nj]=1;
                        dfs(dfs,ni,nj,val->next[ board[ni][nj]-'a']);
                        vis[ni][nj]=0;
                    }
                }
            }
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp.trie->next[board[i][j]-'a']!=NULL){
                    vis[i][j]=1;
                    dfs(dfs,i,j,temp.trie->next[board[i][j]-'a']);
                    vis[i][j]=0;
                }
            }
        }
        // vector<string> ans1(ans.begin(),ans.end());
        return ans;
    }
};