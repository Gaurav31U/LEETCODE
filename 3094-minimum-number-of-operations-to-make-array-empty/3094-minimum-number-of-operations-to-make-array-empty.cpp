class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        map<int,int> mp;
        for(auto it:nums)mp[it]++;
        for(auto it:mp){
            if(it.second==1)return -1;
            ans+=(it.second/3+(it.second%3!=0?1:0));
        }
        return ans;
    }
};