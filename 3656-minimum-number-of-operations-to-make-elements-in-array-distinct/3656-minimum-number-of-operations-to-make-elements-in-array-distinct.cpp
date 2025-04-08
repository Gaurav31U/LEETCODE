class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        for(int i=0;i<nums.size();i+=3){
            set<int> st;
            for(int j=i;j<nums.size();j++){
                st.insert(nums[j]);
            }
            if(st.size()==(nums.size()-i))
                return i/3;
        }
        return ceil(nums.size()/3.0);
    }
};