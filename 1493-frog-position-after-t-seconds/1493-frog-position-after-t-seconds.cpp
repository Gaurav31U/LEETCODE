class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n==1){
            if(target==1)return 1.0;
            else return 0.0;
        }
        vector<int> tmp;
        int level[n+1];
        vector<int> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        int cnt=0;
        q.push(1);
        int vis[n+1],par[n+1];
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        vis[1]=1;
        map<int,int> mp;
        for(int i=2;i<=n;i++){
            if(adj[i].size()==1)mp[i]++;
        }
        while(!q.empty()){
            int m=q.size();
            tmp.push_back(m);
            for(int i=0;i<m;i++){
                int tp=q.front();
                q.pop();
                level[tp]=cnt;
                for(auto it:adj[tp]){
                    if(vis[it]==0){
                        par[it]=tp;
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            cnt++;
        }
        double ans=1.0;
        if(mp.count(target) && level[target]<=t){
            int x=par[target];
            while(x!=-1){
                if(x==1)ans/=double(adj[x].size());
                else ans/=double(adj[x].size()-1);
                x=par[x];
            }
            return ans;
        }
        if(level[target]!=t)return 0.0;
        int x=par[target];
            while(x!=-1){
                if(x==1)ans/=double(adj[x].size());
                else ans/=double(adj[x].size()-1);
                x=par[x];
            }
            return ans;
    }
};