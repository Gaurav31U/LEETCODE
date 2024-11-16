class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int cnt=0;
        for(int i=1;i<k;i++){
            if(nums[i]!=nums[i-1]+1){
                cnt++;
            }
        }
        if(cnt==0)ans.push_back(nums[k-1]);
        else ans.push_back(-1);
        for(int i=k;i<nums.size();i++){
            if(nums[i-1]+1!=nums[i])cnt++;
            if(nums[i-k]+1!=nums[i-k+1])cnt--;
            if(cnt==0)ans.push_back(nums[i]);
            else ans.push_back(-1);
        }
        return ans;
    }
};