class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int N = stones.size();
        for (int i = 1; i < N; ++i) stones[i] += stones[i - 1];
		int dp = stones.back();
        for (int i = N - 2; i > 0; --i) dp = max(dp, stones[i] - dp);  
        return dp;
    }
};