class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long s=0;
        map<int,int> mp;
        for(int i=0;i<k;i++){
            s+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()==k)
        ans=s;
        for(int i=k;i<nums.size();i++){
            s-=nums[i-k];
            s+=nums[i];
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            if(mp.size()==k)
            ans=max(ans,s);
        }
        return ans;
    }
};