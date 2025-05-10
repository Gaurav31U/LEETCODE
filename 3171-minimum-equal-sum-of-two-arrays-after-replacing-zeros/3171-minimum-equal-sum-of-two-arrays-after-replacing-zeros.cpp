class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long z1=0,z2=0;
        long long sum1=0,sum2=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]!=0)sum1+=nums1[i];
            else z1++;
        }
        for(int j=0;j<nums2.size();j++){
            if(nums2[j]!=0)sum2+=nums2[j];
            else z2++;
        }
        if(sum1!=sum2 && z1==0 && z2==0)return -1;
        if(z1==0){
            if(sum1<sum2+z2)return -1;
            if(sum1>sum2 && z2!=0)return sum1;
        }else
         if(z2==0){
            if(sum1+z1>sum2)return -1;
            if(sum1<sum2 && z1!=0)return sum2;
        }
        return max(z1+sum1,sum2+z2);
    }
};