class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long l=0,r=INT_MAX;
        while(l<r){
            long long mid=(l+r)/2;
            int cnt=1,sum=0;
            for(int i=0;i<nums.size();i++){
                sum+=nums[i];
                if(sum>mid){
                    cnt++;
                    sum=nums[i];
                    if(sum>mid){
                        cnt=k+1;
                        break;
                    }
                }
            }
            if(cnt<=k){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};