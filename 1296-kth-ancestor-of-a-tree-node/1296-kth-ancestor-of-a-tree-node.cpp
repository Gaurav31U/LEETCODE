class TreeAncestor {
public:
    int lca[50001][21];
    int level[50001];
    vector<int> adj[50001];
    void dfs(int u,int l,int par){
        level[u]=l;
        lca[u][0]=par;
        for(auto v:adj[u]){
            if(v!=par){
                dfs(v,l+1,u);
            }
        }
    }
    int LCA(int b,int d){
        while(d>0){
            int i=log2(d);
            b=lca[b][i];
            if(b<0)return -1;
            d-=(1<<i);
        }
        return b;
    }
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0;i<n;i++){
            if(parent[i]==-1)continue;
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        memset(lca,-1,sizeof(lca));
        dfs(0,0,-1);
        for(int j=1;j<20;j++){
            for(int i=0;i<n;i++){
                if(lca[i][j-1]!=-1){
                    int par=lca[i][j-1];
                    lca[i][j]=lca[par][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        return LCA(node,k);
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */