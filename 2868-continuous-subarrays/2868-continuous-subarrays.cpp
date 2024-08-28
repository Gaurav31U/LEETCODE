class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        map<int,int> mp;
        set<int> st;
        int j=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            st.insert(nums[i]);
            int a=*(--st.end());
            int b=*(st.begin());
            if(abs(a-b)>2){
                while(j<nums.size() && abs(a-b)>2){
                    mp[nums[j]]--;
                    if(mp[nums[j]]==0){
                        st.erase(st.find(nums[j]));
                    }
                    a=*(--st.end());
                    b=*(st.begin());
                    j++;
                }
                ans+=(i-j+1);
            }else{
                ans+=(i-j+1);
            }
        }
        return ans;
    }
};