class Solution {
public:
    int N;
    int ans;
    int vis[501];
    vector<int> adj[501];
    void bfs(int u,int d){
        vis[u]=1;
        queue<pair<int,int>> q;
        q.push({u,0});
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            if(tp.first==(N-1)){
                ans=min(ans,tp.second);
                break;
            }
            for(auto v:adj[tp.first]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push({v,tp.second+1});
                }
            }
        }
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        ans=n-1;
        N=n;
        vector<int> val;
        for(int i=0;i<n;i++)
            adj[i].push_back(i+1);
        for(auto it:queries){
            adj[it[0]].push_back(it[1]);
            memset(vis,0,sizeof(vis));
            bfs(0,0);
            val.push_back(ans);
        }
        return val;
    }
};