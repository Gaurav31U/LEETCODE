class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        int t=0;
        for(auto it:nums)t=max(t,it);
        int cnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(t==nums[i]){
                cnt++;
            }
            while(j<n && cnt>=k){
                if(cnt>=k)ans+=(n-i);
                if(nums[j]==t)cnt--;
                j++;
            }
        } 
        return ans;
    }
};