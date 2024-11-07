class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        unordered_map<string,vector<string>> adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int cnt=0;
                for(int k=0;k<m;k++)if(strs[i][k]==strs[j][k]){
                    cnt++;
                }
                if(cnt==m-2 || cnt==m){
                    adj[strs[i]].push_back(strs[j]);
                    adj[strs[j]].push_back(strs[i]);
                }
            }
        }
        int cnt=0;
        unordered_map<string,int> vis;
        auto dfs=[&](auto&& dfs,string s)->void{
            vis[s]=1;
            for(auto it:adj[s]){
                if(!vis.count(it))dfs(dfs,it);
            }
        };
        for(int i=0;i<strs.size();i++){
            if(!vis.count(strs[i])){
                cnt++;
                dfs(dfs,strs[i]);
            }
        }
        return cnt;

    }
};