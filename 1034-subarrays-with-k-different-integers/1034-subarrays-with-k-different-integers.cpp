class Solution {
public:
    int fun(vector<int> nums,int k){
        int ans=0,n=nums.size();
        unordered_map<int,int> mp,last;
        int j=0;
        int cnt=0;
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==0){
                if(cnt==k){
                    while(j<n && cnt==k){
                        mp[nums[j]]--;
                        if(mp[nums[j]]==0)cnt--;
                        j++;
                    }
                    mp[nums[i]]++;
                    cnt++;
                }else{
                    cnt++;
                    mp[nums[i]]++;
                }
            }else{
                mp[nums[i]]++;
            }
            if(cnt<=k)s1+=(i-j+1);
        }
        return s1;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};