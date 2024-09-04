class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        unordered_map<int,int> mp;
        for(int i=0;i<n-1;i++){
            mp[i]=i+1;
        }
        cout<<mp.size();
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            if(!mp.count(u) || mp[u]>v){
                ans[i]=mp.size();
                continue;
            }
            int j=mp[u];
            while(j<v){
                int t=j;
                j=mp[j];
                mp.erase(t);
            }
            mp[u]=v;
            ans[i]=mp.size();
        }
        return ans;
    }
};