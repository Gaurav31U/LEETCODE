class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        int inc[1001],dec[1001];
        for(int i=0;i<n;i++)inc[i]=1,dec[i]=1;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    inc[i]=max(inc[i],inc[j]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    dec[i]=max(dec[i],dec[j]+1);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(inc[i]>1 && dec[i]>1)
            ans=min(ans,n-inc[i]-dec[i]+1);
        }
        return ans;
    }
    
};