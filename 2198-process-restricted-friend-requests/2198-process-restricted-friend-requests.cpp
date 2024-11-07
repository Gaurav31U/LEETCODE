class Solution {
public:
    int par[1001];
    int sz[1001];
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
    void build(int n){
        for(int i=0;i<=n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        vector<pair<int,int>> temp;
        for(auto it:requests){
            int a=it[0];
            int b=it[1];

            int c=0;
            build(n);
            for(auto i:temp)merge(i.first,i.second);
            merge(a,b);
            for(auto i:restrictions){
                if(find_parent(i[0])==find_parent(i[1]))c++;
            }

            if(c==0){
                ans.push_back(true);
                temp.push_back({a,b});
            }else ans.push_back(false);
        }
        return ans;
    }
};