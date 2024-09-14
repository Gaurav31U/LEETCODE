class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        // Greedy & Maths  &&  All values in nums are distinct. 
        int n=nums.size();
        long long ans=n;
        vector<pair<int,int>> tmp;
        for(int i=0;i<nums.size();i++)
            tmp.push_back({nums[i],i});
        sort(tmp.begin(),tmp.end());
        for(int i=1;i<nums.size();i++){
            if(tmp[i].second<tmp[i-1].second)
                ans+=n-i;
        }
        return ans;
    }
};