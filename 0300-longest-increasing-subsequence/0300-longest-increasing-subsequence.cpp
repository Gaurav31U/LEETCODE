class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            auto j=lower_bound(ans.begin(),ans.end(),n);
            if(j==ans.end())ans.push_back(n);
            else
                *j=n;
        }
        return ans.size();
    }
};