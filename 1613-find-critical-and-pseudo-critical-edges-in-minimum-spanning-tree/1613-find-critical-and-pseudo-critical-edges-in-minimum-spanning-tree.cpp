class Solution {
public:
    int par[102];
    int sz[102];
    int find_parent(int n){
        if(par[n]==n)return n;
        return par[n]=find_parent(par[n]);
    }
    void merge(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            par[b]=a;
            sz[a]+=sz[b];
        } 
    }
    void init(int n){
        for(int i=0;i<=n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        vector<vector<int>> ans;
        sort(edges.begin(),edges.end(),[&](vector<int> a,vector<int> b){
            return a[2]<b[2];
        });
        vector<int> x,y;
        int s1=0;
        int mn=edges[0][2];
        init(n);
        for(int j=0;j<edges.size();j++){
            int a=find_parent(edges[j][0]);
            int b=find_parent(edges[j][1]);
            if(a!=b){
                s1+=edges[j][2];
                merge(a,b);
            }
        }
        for(int i=0;i<edges.size();i++){
            int s2=0;
            init(n+1);
            for(int j=0;j<edges.size();j++){
                if(i!=j){
                    int a=find_parent(edges[j][0]);
                    int b=find_parent(edges[j][1]);
                    if(a!=b){
                        s2+=edges[j][2];
                        merge(a,b);
                    }
                }
            }
            int mx=*max_element(sz,sz+n);
            if(s1!=s2 || mx!=n){
                x.push_back(edges[i][3]);
                continue;
            }
            init(n+1);
            merge(edges[i][0],edges[i][1]);
            s2=edges[i][2];
            for(int j=0;j<edges.size();j++){
                if(i!=j){
                    int a=find_parent(edges[j][0]);
                    int b=find_parent(edges[j][1]);
                    if(a!=b){
                        s2+=edges[j][2];
                        merge(a,b);
                    }
                }
            }
            if(s1==s2)y.push_back(edges[i][3]);
        }
        return {x,y};
    }
};