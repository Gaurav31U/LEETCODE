class SegmentTree{
    public:
    int n;
    vector<int> seg;
    SegmentTree(int n){
        this->n=n;
        seg.resize(n<<2,INT_MAX/4);
    }
    int query(int s,int l,int r,int ql,int qr){
        if(l>qr || r<ql){
            return INT_MAX/4;
        }
        if(l>=ql && r<=qr){
            return seg[s];
        }
        int mid=(l+r)/2;
        return min(query(2*s,l,mid,ql,qr),query(2*s+1,mid+1,r,ql,qr));
    }
    void update(int s,int l,int r,int idx,int val){
        if(l>idx || r<idx)return;
        if(l==r){
            seg[s]=val;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)update(2*s,l,mid,idx,val);
        else update(2*s+1,mid+1,r,idx,val);
        seg[s]=min(seg[2*s],seg[2*s+1]);
    }

};
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<SegmentTree> col(m, SegmentTree(n));
        vector<SegmentTree> row(n, SegmentTree(m));
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        dp[n-1][m-1]=1;
        col[m-1].update(1,1,n,n-1,1);
        row[n-1].update(1,1,m,m-1,1);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)continue;
                int p=grid[i][j];
                int c = col[j].query(1, 1, n, i + 1, min(n, i + p));
                int r = row[i].query(1, 1, m, j + 1, min(m, j + p));
                if(i==n-1)c=INT_MAX/4;
                if(j==m-1)r=INT_MAX/4;
                dp[i][j]=min(c,r)+1;
                col[j].update(1,1,n,i,dp[i][j]);
                row[i].update(1,1,m,j,dp[i][j]);
            }
        }
        if(dp[0][0]>=INT_MAX/4)return -1;
        return dp[0][0];
    }
};