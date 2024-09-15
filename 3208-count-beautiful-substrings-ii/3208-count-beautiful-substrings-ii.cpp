class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        unordered_map<int, vector<int>> grps;
        grps[0].push_back(0);

        string vowels("aeiou");
        for (int i = 0, presum = 0; i < s.size(); i++) {
            vowels.find(s[i]) != string::npos ? ++presum : --presum;
            grps[presum].push_back(i + 1);
        }
        
        int x;
        for (x = 1; x <= k && x * x % k; x++);
        x *= 2;

        int64_t ans = 0;
        for (auto &[_, grp] : grps) {
            vector<int> mod(x);
            for (int i : grp)
                ans += mod[i % x]++;
        }
        return ans;
    }
};