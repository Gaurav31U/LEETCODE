class Solution {
public:
    int par[100001];
    int sz[100001];
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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<=n;i++){
            par[i]=i;
            sz[i]=1;
        }
        sort(edgeList.begin(),edgeList.end(),[&](vector<int> a,vector<int> b){
            return a[2]<b[2];
        });
        for(int i=0;i<queries.size();i++)queries[i].push_back(i);
        sort(queries.begin(),queries.end(),[&](vector<int> a,vector<int> b){
            return a[2]<b[2];
        });
        int e=0;
        for(int i=0;i<queries.size();i++){
            int cur=queries[i][2];
            while(e<edgeList.size() && edgeList[e][2]<cur){
                int a=find_parent(edgeList[e][0]);
                int b=find_parent(edgeList[e][1]);
                if(a!=b){
                    merge(a,b);
                }
                e++;
            }
            if(find_parent(queries[i][0])==find_parent(queries[i][1])){
                ans[queries[i][3]]=true;
            }

        }
        return ans;
    }
};