class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        long long ans=0,mod=1e9+7;
        long long sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            (ans+=((nums[i]*1ll*nums[i])%mod*(sum+nums[i]))%mod)%=mod;
            (sum*=2)%=mod;
            (sum+=nums[i])%=mod;
        }
        return ans;
    }
};