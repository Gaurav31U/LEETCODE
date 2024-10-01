class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=0,r=1e18;
        long long ans=LLONG_MAX;
        while(l<=r){
            long long mid=(l+r)/2;
            long long sum=0; 
            long long cnt=0;
            
            for(auto it:workerTimes){
                long long p=sqrt(it*1ll*it+(long double)8*mid*it);
                p=p-it;
                p/=double(2*it);
                cnt+=floor(p);
                if(cnt>=mountainHeight)break;
            }
            if(cnt>=mountainHeight){
                ans=min(mid,ans);
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};