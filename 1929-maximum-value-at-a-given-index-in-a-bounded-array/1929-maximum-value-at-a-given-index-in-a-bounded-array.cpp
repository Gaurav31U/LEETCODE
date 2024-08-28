class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l=1,r=1e9;
        int ans=0;
        long long a=index;
        long long b=n-index-1;
        while(l<=r){
            int mid=(l+r)/2;
            long long sum=mid,temp=mid;
            if(a<temp){
                sum+=(a*temp-(a*(1+a))/2);
            }else{
                if(temp>1)
                temp--;
                sum+=(temp*(temp+1))/2;
                sum+=(a-temp);
            }
            temp=mid;
            if(b<temp){
                sum+=(b*temp-(b*(1+b))/2);
            }else{
                if(temp>1)
                temp--;
                sum+=(temp*(temp+1))/2;
                sum+=(b-temp);
            }
            if(sum<=maxSum){
                ans=max(mid,ans);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};