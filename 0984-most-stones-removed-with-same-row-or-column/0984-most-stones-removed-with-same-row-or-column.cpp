static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> col[10001],row[10001];
        for(auto it:stones){
            col[it[0]].push_back(it[1]);
            row[it[1]].push_back(it[0]);
        }
        int c=0,ans=0;
        map<pair<int,int>,int> vis;
        auto dfs=[&](auto&& dfs,int i,int j)->void{
            c++;
            vis[{i,j}]=1;
            for(auto it:row[j]){
                if(vis.find({it,j})==vis.end()){
                    dfs(dfs,it,j);
                }
            }
            for(auto it:col[i]){
                if(vis.find({i,it})==vis.end()){
                    dfs(dfs,i,it);
                }
            }
        };
        for(auto it:stones){
            if(vis.find({it[0],it[1]})==vis.end()){
                c=0;
                dfs(dfs,it[0],it[1]);
                ans+=(c-1);
            }
        }
        return ans;
    }
};