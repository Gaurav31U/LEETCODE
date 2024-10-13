class Solution {
public:
    vector<int> adj[200001];
    int vis[200001],par[200001];
    int node,dis;
    void dfs(int u,int p,int d){
        if(dis<d){
            dis=d;
            node=u;
        }
        vis[u]=1;
        par[u]=p;
        for(auto v:adj[u]){
            if(vis[v]==0)dfs(v,u,d+1);
        }
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // find mid of diameter of both trees and then connect them
        if(edges1.empty() && edges2.empty())return 1;
        if(edges1.size()<edges2.size())swap(edges1,edges2);
        vector<int> ed;
        for(auto it:edges1){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,0);
        dis=0;
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        dfs(node,-1,0);
        if(edges2.empty())return dis+(edges1.size()>1?0:1);
        vector<int> a;
        while(node!=-1){
            a.push_back(node);
            node=par[node];
        }
        dis=0;
        int inc=1e5;
        for(auto it:edges2){
            adj[inc+it[0]].push_back(inc+it[1]);
            adj[inc+it[1]].push_back(inc+it[0]);
        }
        dfs(inc+0,-1,0);
        dis=0;
        memset(par,-1,sizeof(par));
        memset(vis,0,sizeof(vis));
        dfs(node,-1,0);
        vector<int> b;
        while(node!=-1){
            b.push_back(node);
            node=par[node];
        }
        ed.push_back(a[a.size()/2]);
        ed.push_back(b[b.size()/2]);
        adj[ed[0]].push_back(ed[1]);
        adj[ed[1]].push_back(ed[0]);
        memset(vis,0,sizeof(vis));
        dis=0;
        dfs(0,-1,0);
        dis=0;
        memset(vis,0,sizeof(vis));
        dfs(node,-1,0);
        return dis;
    }
};