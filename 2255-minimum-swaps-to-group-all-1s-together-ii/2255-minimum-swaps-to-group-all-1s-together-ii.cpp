class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt=0;
        for(auto it:nums)if(it==1)cnt++;
        int ans=nums.size();
        int n=ans;
        int c=0;
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        for(int i=0;i<cnt;i++){
            if(nums[i]==0)c++;
        }
        ans=min(c,ans);
        for(int i=cnt;i<nums.size();i++){
            if(nums[i]==0)c++;
            if(nums[i-cnt]==0)c--;
            ans=min(ans,c);
        }
        return ans;
    }
};