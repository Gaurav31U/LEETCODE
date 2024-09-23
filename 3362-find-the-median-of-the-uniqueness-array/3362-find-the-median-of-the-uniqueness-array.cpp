class Solution {
public:
    // given k unique, find the number of subarrays that contains k unique
    long long helper1(vector<int> &nums, long long k) {
        if(k <= 0) return 0;
        unordered_map<long long, long long> hm;
        long long l = 0, count = 0;
        for(long long r = 0; r < nums.size(); ++r) {
            hm[nums[r]]++;
            while(hm.size() > k) {
                hm[nums[l]]--;
                if(hm[nums[l]] == 0) hm.erase(nums[l]);
                l++;
            }
            count += (r - l + 1); // valid subarray
        }
        return count;
    }
    long long helper2(vector<int> &nums, long long k) {
        return helper1(nums, k);
    }
    int bs(vector<int> &nums, long long k, long long l, long long h) {
        while(l <= h) {
            long long m = l + (h-l)/2;
            long long n = helper2(nums, m);
            // cout << m << ", " << n << ", " << k << "\n";
            if(n == k) return m;
            else if(n > k) h = m - 1;
            else l = m + 1;
        }
        // cout << "\n";
        // cout << l << ", " << k << "\n";
        return l;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        // find the max uniqueness
        set<int> set;
        for(auto &num : nums) set.insert(num);
        long long maxU = set.size();
        long long maxS = 0;
        for(int i = 1; i <= nums.size(); ++i) maxS += i;
        if(maxS % 2 != 0) return bs(nums, maxS / 2 + 1, 1, maxU);
        return (bs(nums, maxS / 2, 1, maxU) + bs(nums, maxS / 2 + 1, 1, maxU)) / 2;
    }
};