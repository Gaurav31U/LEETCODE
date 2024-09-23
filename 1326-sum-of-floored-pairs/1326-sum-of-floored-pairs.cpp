class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<long long>arr(200005,0);
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            for(int i=it.first;i<200005;i+=it.first)
                arr[i]+=it.second;
        }
        for(int i=1;i<200005;i++){
            arr[i]+=arr[i-1];
        }
        long long ans=0;
        int mod=1e9+7;
        for(auto it:nums)(ans+=arr[it])%=mod;
        return ans;
    }
};