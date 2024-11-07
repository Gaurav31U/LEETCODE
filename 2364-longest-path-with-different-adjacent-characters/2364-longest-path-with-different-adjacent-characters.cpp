class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int ans=0;
        int par=0;
        vector<int> adj[100001];
        for(int i=0;i<parent.size();i++){
            if(parent[i]!=-1){
                adj[i].push_back(parent[i]);
                adj[parent[i]].push_back(i);
            }else par=i;
        }
        int vis[100001];
        memset(vis,0,sizeof(vis));
        auto dfs=[&](auto&& dfs,int n)->int{
            vis[n]=1;
            int dis=1;
            int mx=0;
            vector<int> temp;
            for(auto it:adj[n]){
                if(vis[it]==0){
                    if(s[n]!=s[it]){
                        int next=dfs(dfs,it);
                        mx=max(mx,next);
                        temp.push_back(next);
                    }else{
                        dfs(dfs,it);
                    }
                }
            }
            for(int i=0;i<temp.size();i++){
                for(int j=i+1;j<temp.size();j++){
                    ans=max(ans,temp[i]+temp[j]+1);
                }
            }
            ans=max(ans,mx+dis);
            return mx+dis;
        };
        dfs(dfs,par);
        return ans;
    }
};