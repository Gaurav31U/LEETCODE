class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
       if(nums1.size()<nums2.size())swap(nums1,nums2);
       int n=nums1.size();
       int m=nums2.size();
       if(6*m<n)return -1;
       int s1=0,s2=0;
       for(auto it:nums1)s1+=it;
       for(auto it:nums2)s2+=it;
       int ans=0;
       for(int k=6;k>=2;k--){
       if(s1>s2){
            // sort(nums1.begin(),nums1.end(),greater<int>());
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]==k){
                s1-=(nums1[i]-1);
                ans++;
                }
                if(s1<=s2){
                    return ans;
                }
            }
            // sort(nums2.begin(),nums2.end());
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==(7-k)){
                    s2+=(6-nums2[i]);
                    ans++;
                }
                if(s1<=s2){
                    return ans;
                }
            }
       }else if(s1<s2){
            // sort(nums1.begin(),nums1.end());
            for(int i=0;i<nums1.size();i++){
                if(nums1[i]==(7-k)){
                    s1+=(6-nums1[i]);
                    ans++;
                }
                if(s1>=s2){
                    return ans;
                }
            }
            // sort(nums2.begin(),nums2.end(),greater<int>());
            for(int i=0;i<nums2.size();i++){
                if(nums2[i]==k){
                    s2-=(nums2[i]-1);
                    ans++;
                }
                if(s1>=s2){
                    return ans;
                }
            }

       }
       }
       return ans;
    }
};