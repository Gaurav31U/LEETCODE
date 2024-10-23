class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int mx=nums.back();
        for(int i=n-2;i>=0;i--){
            if(mx<nums[i]){
                int m=-1;
                for(int j=2;j<=sqrt(nums[i]);j++){
                    if(nums[i]%j==0){
                        int p=nums[i]/j;
                        if(nums[i]/p<=mx){
                            m=max(m,nums[i]/p);
                            break;
                        }
                    }
                }
                if(m==-1)return -1;
                mx=min(m,mx);
                ans++;
            }
            mx=min(mx,nums[i]);
        }
        return ans;
    }
};