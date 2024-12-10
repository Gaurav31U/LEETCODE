#define FIO                                                                    \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        FIO sort(nums.begin(), nums.end());
        return count(upper, nums) - count(lower - 1, nums);
    }

private:
    long long count(int mx, vector<int>& nums) {
        int l = 0, n = nums.size(), r = n - 1;
        long long ans = 0;
        while (l < r) {
            while (r > l && nums[l] + nums[r] > mx)
                r--;
            ans += r - l++;
        }
        return ans;
    }
};