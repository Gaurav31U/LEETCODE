class Solution {
public:
    bool isPrintable(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        unordered_map<int,vector<int>> mp;
        unordered_set<int> cs;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++){
            int c=g[i][j];
            cs.insert(c);
            if(c==0) continue;
            auto & v=mp[c];
            if(v.empty()){
                v={i,i,j,j};
            }else{
                v[0]=min(v[0],i);
                v[1]=max(v[1],i);
                v[2]=min(v[2],j);
                v[3]=max(v[3],j);
            }
        }
        unordered_map<int,unordered_set<int>> e;
        unordered_map<int,int> ind;
        for(auto& [c,v]:mp){
            int minx=v[0],maxx=v[1],miny=v[2],maxy=v[3];
            for(int i=minx;i<=maxx;i++) for(int j=miny;j<=maxy;j++){
                int d=g[i][j];
                if(d==0) return false;
                if(d==c or e[d].count(c)) continue;
                e[d].insert(c);
                ind[c]++;
            }
        }
        queue<int> q;
        for(auto c:cs){
            if(ind.count(c)) continue;
            q.push(c);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:e[u]){
                if(--ind[v]) continue;
                q.push(v);
            }
        }
        for(auto&[c,v]:ind){
            if(v) return false;
        }
        return true;
    }
};