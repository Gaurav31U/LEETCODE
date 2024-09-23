class MST{
    private:
        int n;
        struct Data{int x, y, sum;};
        vector<vector<Data>> tree;
        vector<Data> Merge(vector<Data>&a,vector<Data>&b)
        {
            int l1 = a.size(), l2 = b.size(), i = 0, j = 0, k = 0;
            vector<Data> c(l1+l2);
            while(i < l1 && j < l2){
                if(a[i].x < b[j].x) c[k++] = a[i++];
                else c[k++] = b[j++];
            }
            while(i < l1) c[k++] = a[i++];
            while(j < l2) c[k++] = b[j++];
            for(int i=c.size()-2; i>-1; --i)
                c[i].sum = max(c[i].sum,c[i+1].sum);
            return c;
        }
        int query(int e,int x,int y,int l,int r,int i)
        {
            if(y < l || x > r) return -1;
            if(l >= x && r <= y){
                auto &v = tree[i];
                Data d = {e,-1,-1};
                int id = lower_bound(begin(v), end(v), d,
                [](const Data& d1, const Data& d2){
                    return d1.x < d2.x;
                })-begin(v);
                if(id == v.size()) return -1;
                return v[id].sum;
            }
            int m = (l+r)>>1;
            int left = query(e,x,y,l,m,2*i+1);
            int right = query(e,x,y,m+1,r,2*i+2);
            return max(left,right);
        }
        void build(int l,int r,int i,vector<pair<int,int>>&v)
        {
            if(l == r){
                tree[i] = {{v[l].second,v[l].first,v[l].first+v[l].second}};
                return;
            }
            int m = (l+r)>>1;
            build(l,m,2*i+1,v);
            build(m+1,r,2*i+2,v);
            tree[i] = Merge(tree[2*i+1],tree[2*i+2]);
        }
    public:
        MST(int n,vector<pair<int,int>>&v)
        {
            this->n = n;
            tree.resize(4*n);
            build(0,n-1,0,v);
        }
        int query(int x,int y,int e)
        {
            return query(e,x,y,0,n-1,0);
        }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& A, vector<int>& B, vector<vector<int>>& Q) {
        int n = A.size(), m = Q.size();
        vector<int> ans;
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; ++i) v[i] = {A[i],B[i]};
        sort(begin(v),end(v));
        MST mt(n,v);
        for(auto q: Q){
            int x = q[0], y = q[1];
            int l = lower_bound(begin(v),end(v),make_pair(x,-1)) - begin(v);
            int res = mt.query(l,n-1,y);
            ans.push_back(res);
        }
        return ans;
    }
};