static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=*max_element(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<nums.size();i++){
            int j=i;
            while(j<nums.size() && nums[j]==k)j++;
            ans=max(ans,j-i);
            if(i!=j)i=j-1;
        }
        return ans;
    }
};