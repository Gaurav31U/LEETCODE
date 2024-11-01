class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int cnt[1<<16];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                cnt[(nums[i]&nums[j])]++;
            }
        }
        for(auto it:nums){
            for(int i=0;i<(1<<16);i++){
                if((i&it)==0)ans+=cnt[i];
            }
        }
        return ans;
    }
};