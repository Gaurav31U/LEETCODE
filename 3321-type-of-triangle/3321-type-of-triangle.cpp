class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> st;
        sort(nums.begin(),nums.end());
        if(nums[0]+nums[1]<=nums[2])return "none";
        for(auto it:nums)st.insert(it);
        if(st.size()==1)return "equilateral";
        if(st.size()==2)return "isosceles";
        return "scalene";
    }
};