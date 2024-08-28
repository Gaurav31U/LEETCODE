class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        map<int,int> mp;
        int t=0;
        int ans=INT_MAX;
        for(auto it:nums){
            temp.push_back(it%space);
            mp[it%space]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[temp[i]]>t){
                ans=nums[i];
                t=mp[temp[i]];
            }
        }
        return ans;
    }
};