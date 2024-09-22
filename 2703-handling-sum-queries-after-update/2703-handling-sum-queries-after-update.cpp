class Solution {
public:
    static const int N=5e5+1;
    long long seg[N],lazy[N];
    long long arr[N];
    void build(int s,int i,int j){
        if(i==j){
            seg[s]=arr[i];
            return;
        }
        int mid=(i+j)/2;
        build(2*s,i,mid);
        build(2*s+1,mid+1,j);
        seg[s]=seg[2*s]+seg[2*s+1];
    }
    void updateRange(int s,int i,int j,int a,int b){
        if(lazy[s]!=0){
            if(lazy[s])seg[s]=j-i+1-seg[s];
            lazy[s]=0;
            if(i!=j){
                lazy[2*s]^=1;
                lazy[2*s+1]^=1;
            }	
        }

        if(j<a || b<i)return;
        if(i>=a && j<=b){
            seg[s]=j-i+1-seg[s];
            if(i!=j){
                lazy[2*s]^=1;
                lazy[2*s+1]^=1;
            }
            return;
        }
        if(i==j){
            arr[i]^=1;
            seg[s]=arr[i];
            return;
        }
        int mid=(i+j)/2;
        updateRange(2*s,i,mid,a,b);
        updateRange(2*s+1,mid+1,j,a,b);
        seg[s]=seg[2*s]+seg[2*s+1];
    }
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> ans;
        long long p=0,sum=0;
        for(auto it:nums2)sum+=it;
        int n=nums1.size();
        for(int i=1;i<=n;i++)arr[i]=nums1[i-1];
        build(1,1,n);
        for(int i=0;i<queries.size();i++){
            int t=queries[i][0];
            if(t==1){
                updateRange(1,1,n,queries[i][1]+1,queries[i][2]+1);
            }else if(t==2){
                p=queries[i][1];
                sum+=p*seg[1];
            }else{
                ans.push_back(sum);
            }
        }
        return ans;
    }
};