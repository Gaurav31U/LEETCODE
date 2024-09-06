class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
       int max_val = *max_element(nums.begin(), nums.end());
        if (max_val <= 0) return max_val;
        map<int, long long> dToSum;
        dToSum[INT_MAX] = 0; 
        for (int i = nums.size() - 1; i >= 0; --i) {
            int x = nums[i];
            if (x <= 0) continue;
            int d = x - i;
            long long sum = dToSum.lower_bound(d)->second + x;
            auto it = dToSum.upper_bound(d);
            while (it != dToSum.begin() && (--it)->second <= sum) {
                it = dToSum.erase(it);
            }
            dToSum[d] = sum;
        }
        return dToSum.begin()->second;
    }
};