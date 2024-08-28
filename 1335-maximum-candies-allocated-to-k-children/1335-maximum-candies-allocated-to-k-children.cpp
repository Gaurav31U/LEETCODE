class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=0,r=1e7;
        int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            long long cnt=0;
            for(auto it:candies){
                if(mid==0)break;
                cnt+=it/mid;
            }
            if(cnt>=k){
                l=mid+1;
                ans=max(ans,mid);
            }else r=mid-1;
        }
        return ans;
    }
};