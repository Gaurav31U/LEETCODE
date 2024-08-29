class Solution {
public:
    int mod=1e9+7;
    int sumOfPowers(vector<int>& nums, int K) {
        sort(nums.begin(),nums.end());
        map<long long,int> mp;
        auto get=[&](auto&& get,int i,int k,int diff)->int{
            if(k==0)return diff;
            long long t=i+100*k+diff*10000ll;
            if(mp.count(t))return mp[t];
            int ans=0;
            for(int j=i+1;j<nums.size();j++){
                (ans+=get(get,j,k-1,min(diff,abs(nums[i]-nums[j]))))%=mod;
            }
            return mp[t]=ans;
        };      
        int ans=0;
        for(int i=0;i<nums.size();i++){
            (ans+=get(get,i,K-1,INT_MAX))%=mod;
        }
        return ans;
    }
};