class Solution {
public:
    int seg[400001],arr[100001];
    void build(int s,int i,int j){
        if(i==j){
            seg[s]=arr[i];
            return;
        }
        int mid=(i+j)/2;
        build(2*s,i,mid);
        build(2*s+1,mid+1,j);
        seg[s]=seg[2*s] | seg[2*s+1];
    }
    int query(int s,int i,int j,int l,int r){
        if(j<l || i>r)return 0;
        if(l<=i && j<=r){
            return seg[s];
        }
        int mid=(i+j)/2;
        int x=query(2*s,i,mid,l,r);
        int y=query(2*s+1,mid+1,j,l,r);
        return x|y;
    }
    int minimumDifference(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=1;i<=n;i++)arr[i]=nums[i-1];
        build(1,1,n);
        cout<<query(1,1,n,1,2);
        for(int i=0;i<n;i++){
            int l=i+1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                int p=query(1,1,n,i+1,mid);
                if(p>=k){
                    ans=min(ans,abs(k-p));
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            l=i+1,r=n;
            while(l<=r){
                int mid=(l+r)/2;
                int p=query(1,1,n,i+1,mid);
                if(p<=k){
                    ans=min(ans,abs(k-p));
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        return ans;
    }
};