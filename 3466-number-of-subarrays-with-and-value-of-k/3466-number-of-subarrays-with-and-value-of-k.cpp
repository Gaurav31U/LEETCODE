class Solution {
public:

    long long countSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums, k+1);
    }
    void add_num(vector<int>& buffer, int num) {
        for(int i = 0; i < 32; i++) {
            if(num & 1)
                buffer[i]++;
            num = num >> 1;
        }
    }
    void minus_num(vector<int>& buffer, int num) {
        for(int i = 0; i < 32; i++) {
            if(num & 1)
                buffer[i]--;
            num = num >> 1;
        }
    }
    int calcnum(vector<int>& buffer, int left, int right) {
        int _size = right - left + 1;
        int res = 0;
        for(int i = 0; i < 32; i++) {
            if(buffer[i] == _size) {
                res += (1<<i);
            }
        }
        return res;
    }
    long long helper(vector<int>& nums, int k) {
        long long res = 0;
        int left = 0;
        int right = 0;
        int N = nums.size();
        vector<int> buffer(32, 0);
        for(;right < N; right++) {
            add_num(buffer, nums[right]);
            while(left <= right && calcnum(buffer, left, right) < k) {
                minus_num(buffer, nums[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};