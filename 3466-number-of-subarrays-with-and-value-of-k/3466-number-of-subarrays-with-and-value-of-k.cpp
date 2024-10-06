class Solution {
public:
    vector<long long> tree ;
    void buildSegmentTree(int s, int l, int r, vector<int>&A){
       if(l == r){
           tree[s] = A[l];
           return;
       }
       int mid = l + (r-l)/2;
       buildSegmentTree(2*s, l, mid, A);
       buildSegmentTree(2*s+1, mid+1, r, A);
       tree[s] = tree[2*s] & tree[2*s+1];
    }
    long long querySegmentTree(int s, int l, int r, int ql, int qr){
       if(ql <= l && qr >= r){ 
           return tree[s] ;
       }
       if( (ql > r) || (qr < l) ){
           return -1ll;  
       }
       int mid = l + (r-l)/2;
       long long L = querySegmentTree(2*s, l, mid, ql, qr);
       long long R = querySegmentTree(2*s + 1, mid+1, r, ql, qr);

       return L & R;
    }
    int binarySearch(int i, int N, int k){
        int start=i, end = N-1;
        while(start < end){
            if(end-start==1) break;
            int mid = start + (end-start)/2;
            long long val = querySegmentTree(1, 0, N-1, i, mid);
            if(val > k){
                start = mid;
            }
            else end = mid;
        }
        
        long long val = querySegmentTree(1, 0, N-1, i, start);
        if(val <= k) return N-start;
        
        val = querySegmentTree(1, 0, N-1, i, end);
        if(val <= k) return N-end;
        
        return 0;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        tree.resize(4*nums.size());
        buildSegmentTree(1, 0, nums.size()-1, nums);
        
        long long Ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            Ans += binarySearch(i, nums.size(), k) - binarySearch(i, nums.size(), k-1) ;
        }
        
        return Ans;
    }
};