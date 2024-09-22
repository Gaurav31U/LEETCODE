class Solution {
public:
    long long solve(vector<int>&n1,vector<int>&n2,long long k,long long t){
        long long tmp=0;
        for(int i=0;i<n1.size();i++){
            if(n1[i]==0){
                if(t>=0)tmp+=n2.size();
            }else if(n1[i]>0){
                long long val=floor((double)t/n1[i]);
                auto it=upper_bound(n2.begin(),n2.end(),val);
                if(it==n2.end() || (*it)>val)it--;
                tmp+=(it-n2.begin()+1);
            }else{
                long long val=ceil((double)t/n1[i]);
                auto it=lower_bound(n2.begin(),n2.end(),val);
                tmp+=(n2.end()-it);
            }
            if(tmp>k)return tmp;
        }
        return tmp;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l=-1e10,r=1e15;
        long long ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(solve(nums1,nums2,k,mid)<k){
                l=mid+1;
            }else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};