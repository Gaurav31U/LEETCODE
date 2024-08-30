class Solution {
public:
    long long lcm_fun(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long ans=1e17;
        int n=coins.size();
        long long l=1;
        long long r=1e15;
        while(l<=r){
            long long mid=(l+r)/2;
            long long val=0;
            for(int i=1;i<(1<<n);i++){
                int p=0;
                long long lcm=1;
                for(int j=0;j<n;j++){
                    if((i&(1<<j))>0){
                        p++;
                        lcm=lcm_fun(coins[j],lcm);
                    }
                }
                long long sum=mid/lcm;
                if(p&1)val+=sum;
                else val-=sum;
            }
            if(val>=k){
                ans=min(mid,ans);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};