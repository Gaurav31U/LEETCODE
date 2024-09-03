class Solution {
public:
    vector<int> prefix_function(vector<int> s) {
        int n = (int)s.size();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> temp;
        for(auto it:pattern)temp.push_back(it);
        temp.push_back(9);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                temp.push_back(0);
            }else if(nums[i]>nums[i-1]){
                temp.push_back(1);
            }else temp.push_back(-1);
        }
        auto vi=prefix_function(temp);
        int ans=0;
        for(int i=0;i<vi.size();i++){
            if(vi[i]==pattern.size())ans++;
        }
        return ans;

    }
};