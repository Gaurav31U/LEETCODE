class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> temp(nums.size()+1,0);
        for(auto it:queries){
            temp[it[0]]++;
            temp[it[1]+1]--;
        }
        for(int i=0;i<temp.size()-1;i++){
            temp[i+1]+=temp[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]-=min(nums[i],temp[i]);
        }
        for(auto it:nums)
        if(it>0)return false;
            // cout<<it<<" ";
        return true;
    }
};