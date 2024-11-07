class Solution {
public:
    int par[30001];
    int sz[30001];
    int find_parent(int n){
        if(par[n]==n)return n;
        return par[n]=find_parent(par[n]);
    }
    void merge(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        if(a!=b){
            if(sz[a]<sz[b])swap(a,b);
            par[b]=a;
            sz[a]+=sz[b];
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        for(int i=0;i<=vals.size();i++){
            par[i]=i;
            sz[i]=1;
        }
        vector<int> adj[30001];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        map<int,vector<int>> mp;
        for(int i=0;i<vals.size();i++){
            mp[vals[i]].push_back(i);
        }
        for(auto&[val,nodes]:mp){
            for(auto it:nodes){
                for(auto i:adj[it]){
                    if(vals[i]<=vals[it]){
                        merge(i,it);
                    }
                }
            }
            map<int,int> grp;
            for(auto it:nodes)grp[find_parent(it)]++;
            for(auto it:grp){
                ans+=(it.second*(it.second+1))/2;
            }
        }
        return ans;
    }
};