class Solution {
public:
    bool solve(vector<int> &nums,int r,int k,long long mid){
        int n=nums.size();
        vector<long long> add(n,0);
        long long cur=0;
        for(int i=0;i<r;i++)cur+=nums[i];
        for(int i=0;i<n;i++){
            if(i+r<n){
                cur+=nums[i+r];
                cur+=add[i+r];
            }
            if(cur<mid){
                long long need=mid-cur;
                if(need>k)return false;
                k-=need;
                cur=mid;
                add[min(i+r,n-1)]=need;
            }
            if(i-r>=0){
                cur-=nums[i-r];
                cur-=add[i-r];
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int R, int k) {
        // binary search
        long long sum=0;
        for(auto it:stations)sum+=it;
        long long l=0,r=sum+k;
        long long ans=0;
        while(l<=r){
            long long mid=(l+r)/2;
            if(solve(stations,R,k,mid)){
                ans=max(mid,ans);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};