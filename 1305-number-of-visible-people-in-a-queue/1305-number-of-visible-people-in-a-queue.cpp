class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans;
        int cnt=0;
        ans.push_back(0);
        vector<int> st;
        st.push_back(heights.back());
        int prev=heights.back();
        for(int i=heights.size()-2;i>=0;i--){
            if(prev>heights[i])ans.push_back(1);
            else{
                int nums=lower_bound(st.rbegin(),st.rend(),heights[i])-st.rbegin()+1;
                nums=min((int)st.size(),nums);
                ans.push_back(nums);
            } 
            while(!st.empty() && st.back()<heights[i]){
                st.pop_back();
            }
            st.push_back(heights[i]);
            prev=heights[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};