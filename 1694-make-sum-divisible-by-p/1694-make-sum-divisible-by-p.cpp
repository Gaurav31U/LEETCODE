class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        for(auto &it:nums)it%=p;
        vector<int> tmp;
        long long sum=0;
        int n=nums.size();
        int ans=n+1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            tmp.push_back(sum%p);
            if(sum%p==0){
                ans=min(ans,n-i-1);
            }
        }
        sum=0;
        map<int,int> mp;
        mp[0]=n-1;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            if(sum%p==0){
                ans=min(ans,i);
            }
            int t=p-tmp[i]%p;
            if(mp.count(t)){
                ans=min(ans,mp[t]-i-1);
            }
            mp[sum%p]=i;
        }
        if(ans<n)return ans; 
        return -1;
    }
};