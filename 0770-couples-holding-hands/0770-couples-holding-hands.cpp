class Solution {
public:
    int cnt;
    int par[101];
    int sz[101];
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
            cnt--;
        }
    }
    int minSwapsCouples(vector<int>& row) {
       int n=row.size()/2;
       cnt=n;
       for(int i=0;i<=row.size();i++){
           par[i]=i;
           sz[i]=1;
       }
       for(int i=0;i<n;i++){
           int a=row[2*i];
           int b=row[2*i+1];
           merge(a/2,b/2);
       }
       return n-cnt;
    }
};