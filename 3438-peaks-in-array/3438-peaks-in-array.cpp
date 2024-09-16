class Solution {
public:
    struct node{
        int sum,left,right;
    };
    static const int N=4e5;
    node seg[N];
    int arr[N];
    int n;
    node merge(node a,node b){
        node ans;
        ans.sum=a.sum+b.sum;
        if(a.right>a.left && arr[a.right]>arr[a.right-1] && arr[a.right]>arr[b.left]){
            ans.sum++;
        }else if(b.left<b.right && arr[b.left]>arr[a.right] && arr[b.left]>arr[b.left+1]){
            ans.sum++;
        }
        ans.left=a.left;
        ans.right=b.right;
        return ans;
    }
    void build(int s,int i,int j){
        if(i==j){
            seg[s].left=i;
            seg[s].right=j;
            seg[s].sum=0;
            return;
        }
        int mid=(i+j)/2;
        build(2*s,i,mid);
        build(2*s+1,mid+1,j);
        seg[s]=merge(seg[2*s],seg[2*s+1]);
    }
    node query(int s,int i,int j,int qi,int qr){
        if(j<qi || qr<i){
            node tmp;
            tmp.sum=0;
            tmp.left=tmp.right=-1;
            return tmp;
        }
        if(qi<=i && j<=qr){
            return seg[s];
        }
        int mid=(i+j)/2;
        node l=query(2*s,i,mid,qi,qr);
        node r=query(2*s+1,mid+1,j,qi,qr);
        if(l.right!=-1 && r.left!=-1){
            return merge(l,r);
        }else if( l.right != -1 ){
            return l;
        }
        return r;
    }
    void update(int s,int i,int j,int idx,int val){
        if(i==j){
            arr[idx]=val;
            return;
        }
        int mid=(i+j)/2;
        if(idx<=mid)update(2*s,i,mid,idx,val);
        else update(2*s+1,mid+1,j,idx,val);
        seg[s]=merge(seg[2*s],seg[2*s+1]);
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        for(int i=1;i<=n;i++)arr[i]=nums[i-1];
        arr[0]=arr[n+1]=INT_MAX;
        build(1,1,n);
        vector<int> ans;
        for(auto it:queries){
            if(it[0]==1){
                node tmp=query(1,1,n,it[1]+1,it[2]+1);
                ans.push_back(tmp.sum);
            }else{
                update(1,1,n,it[1]+1,it[2]);
            }
        }
        return ans;
    }
};