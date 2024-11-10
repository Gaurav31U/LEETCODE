class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=nums.size()+1;
        vector<int> temp(32,0);
        int l=0;
        int c=0;
        for(int i=0;i<nums.size();i++){
            int c=0;
            for(int j=0;j<30;j++){
                if(nums[i]&(1<<j)){
                    temp[j]++;
                }
                if(temp[j]>0)c|=(1<<j);
            }
            bool ok=false;
            if(c>=k){
                ok=true;
                ans=min(ans,i-l+1);
            }
            while(ok && l<=i){
                ok=false;
                c=0;
                for(int j=0;j<30;j++){
                    if(nums[l]&(1<<j)){
                        temp[j]--;
                    }
                    if(temp[j]>0)c|=(1<<j);
                }
                l++;
                if(c>=k && l<=i){
                    ok=true;
                    ans=min(ans,i-l+1);
                }
            }

        }
        return ans>nums.size()?-1:ans;
    }
};