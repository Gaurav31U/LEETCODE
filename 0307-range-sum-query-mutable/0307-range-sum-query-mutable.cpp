class NumArray {
public:
    int seg[120001];
    int arr[30001];
    int n;
    void build(int s,int i,int j){
        if(i==j){
            seg[s]=arr[i];
            return;
        }
        int mid=(i+j)/2;
        build(2*s+1,i,mid);
        build(2*s+2,mid+1,j);
        seg[s]=seg[2*s+1]+seg[2*s+2];
    }
    int query(int s,int i,int j,int qi,int qj){
        if(j<qi || i>qj)return 0;
        if(i>=qi && j<=qj)return seg[s];
        int mid=(i+j)/2;
        int l=query(2*s+1,i,mid,qi,qj);
        int r=query(2*s+2,mid+1,j,qi,qj);
        return l+r;
    }
    void updat(int s,int i,int j,int ind){
        if(i==j){
            seg[s]=arr[i];
            return;
        }
        int mid=(i+j)/2;
        if(mid<ind)updat(2*s+2,mid+1,j,ind);
        else updat(2*s+1,i,mid,ind);
        seg[s]=seg[2*s+1]+seg[2*s+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<nums.size();i++)arr[i]=nums[i];
        build(0,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        arr[index]=val;
        updat(0,0,n-1,index);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */