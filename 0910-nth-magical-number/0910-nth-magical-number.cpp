class Solution {
public:
    long long solve(long long mid,int a,int b){
        long long n1=mid/a;
        long long n2=mid/b;
        int lcm=(a*b)/__gcd(a,b);
        long long n3=mid/lcm;
        return n1+n2-n3;
    }
    int nthMagicalNumber(int n, int a, int b) {
        int mod=1e9+7;
        long long l=1,r=1e15;
        long long ans=r;
        while(l<=r){
            long long mid=(l+r)/2;
            if(solve(mid,a,b)>=n){
                r=mid-1;
                ans=min(ans,mid);
            }else{
                l=mid+1;
            }
        }
        return ans%mod;
    }
};