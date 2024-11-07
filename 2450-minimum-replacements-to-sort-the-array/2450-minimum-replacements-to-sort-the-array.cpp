class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int mn=nums.back();
        for(int i=nums.size()-1;i>=0;i--){
            if(mn<nums[i]){
                double k=(double)nums[i]/mn;
                k=ceil(k);
                ans+=(k-1);
                int c=nums[i]%mn; 
                if(c!=0){   
                    c=nums[i]/k;
                    mn=min(mn,c);
                }
            }else mn=min(mn,nums[i]);
        }
        return ans;
    }
};