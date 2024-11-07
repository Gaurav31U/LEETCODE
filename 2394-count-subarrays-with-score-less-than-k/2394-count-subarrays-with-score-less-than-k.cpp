class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        long long j=0;
        long long s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s*(i-j+1)<k){
                ans+=(i-j+1);
            }else{
                while(s*(i-j+1)>=k){
                    s-=nums[j];
                    j++;
                }
                if(s*(i-j+1)<k){
                    ans+=(i-j+1);
                }
            }
        }
        return ans;
    }
};