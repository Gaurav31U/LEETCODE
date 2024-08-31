class FenwickTree{
    public:
    int n;
    vector<int> bit;
    FenwickTree(int n){
        this->n=n;
        bit=vector<int>(n+1,0);
    }
    void add(int id,int val){
        while(id<=n){
            bit[id]=max(bit[id],val);
            id+=(-id&id);
        }
    }
    int query(int id){
        int ans=0;
        while(id>0){
            ans=max(ans,bit[id]);
            id-=(-id&id);
        }
        return ans;
    }
};
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        set<int> obPoint;
        int n=5e4+1;
        obPoint.insert(0);obPoint.insert(n);
        FenwickTree tree(n);
        for(auto it:queries)
            if(it[0]==1)
                obPoint.insert(it[1]);
        for(auto it=obPoint.begin();it!=obPoint.end();it++){
            if(it==obPoint.begin())continue;
            auto prv=prev(it);
            int sz=*it-*prv;
            tree.add(*it,sz);
        }
        vector<bool> ans;
        reverse(queries.begin(),queries.end());
        for(auto i:queries){
            if(i[0]==1){
                auto it=obPoint.find(i[1]);
                auto prv=prev(it);
                auto nxt=next(it);
                obPoint.erase(it);
                tree.add(*nxt,*nxt-*prv);
            }
            else{
                auto it=--obPoint.lower_bound(i[1]);
                int mx=i[1]-*it;
                mx=max(mx,tree.query(*it));
                if(mx>=i[2]){
                    ans.push_back(true);
                }else ans.push_back(false);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};