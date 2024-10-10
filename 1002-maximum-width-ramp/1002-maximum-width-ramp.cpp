class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans=0;
        set<pair<int,int>> st;
        for(int i=nums.size()-1;i>=0;i--){
            if(st.empty()){
                st.insert({nums[i],i});
            }else{
                if(nums[i]<=(--st.end())->first){
                    auto it=st.lower_bound({nums[i],0});
                    ans=max(ans,it->second-i);
                }else{
                    st.insert({nums[i],i});
                }
            }
        }
        return ans;
    }
};