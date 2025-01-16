class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        if(n%2==0 && m%2==0)return 0;
        if(n%2==0 && m%2==1){
            for(auto it:nums1)ans^=it;
            return ans;
        }
        if(n%2==1 && m%2==0){
            for(auto it:nums2)ans^=it;
            return ans;
        }
        for(auto it:nums1)ans^=it;
        for(auto it:nums2)ans^=it;
        return ans;
    }
};