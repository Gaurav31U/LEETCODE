class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int k=(1<<maximumBit)-1;
        vector<int> ans;
        int n = nums.size();
        int x=0;
        for(auto it:nums)x^=it;
        for(int i=0;i<n;i++){
            ans.push_back(x^k);
            x^=nums[n-i-1];
        }
        return ans;
    }
};