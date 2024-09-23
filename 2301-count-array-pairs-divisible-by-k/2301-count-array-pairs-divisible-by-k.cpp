class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        map<int,int> mp;
        for(int i=n-1;i>=0;i--){
            int p=__gcd(k,nums[i]);
            int l=k/p;
            for(auto it:mp)
                if(it.first%l==0)
                    ans+=it.second;
            mp[p]++;
        }
        return ans;
    }
};