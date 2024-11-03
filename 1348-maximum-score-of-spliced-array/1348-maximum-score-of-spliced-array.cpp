class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp;
        int s1=0,s2=0;
        for(int i=0;i<nums1.size();i++){
            temp.push_back(nums2[i]-nums1[i]);
            s1+=nums1[i];
            s2+=nums2[i];
        }
        int s=0,sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
            if(sum>=0)s=max(sum,s);
            else sum=0;
            temp[i]*=(-1);
        }
        int ans=max(s1,s2);
        ans=max(s1+s,ans);
        s=0,sum=0;
        for(int i=0;i<temp.size();i++){
            sum+=temp[i];
            if(sum<0)sum=0;
            ans=max(ans,s2+sum);
        }
        // sum=0;
        // for(int i=0;i<vi.size();i++){
        //     sum+=vi[i];
        //     if(sum<0)sum=0;
        //     ans=max(ans,s2+sum);
        // }
        return ans;
    }
};