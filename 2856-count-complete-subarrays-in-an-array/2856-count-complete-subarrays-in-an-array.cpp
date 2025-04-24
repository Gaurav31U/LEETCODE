class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans=0;
        set<int> s;
        for(auto it:nums)s.insert(it);
        int n=s.size();
        for(int i=0;i<nums.size();i++){
            set<int> st;
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
                if(st.size()>=n){
                    ans+=(nums.size()-j);
                    break;
                }
            }
        }
        return ans;
    }
};