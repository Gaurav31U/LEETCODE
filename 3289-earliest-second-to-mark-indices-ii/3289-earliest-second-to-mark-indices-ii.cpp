#define ll long long
class Solution {
    bool ok(const vector<int>& A, const vector<int>& C, int ans) {
        int n = A.size(), m = C.size();
        if (ans == m + 1) {
            return true;
        }
        
        vector<bool> seen(n);
        vector<pair<int, int>> ps;
        for (int j = 0; j < ans; ++j) {
            if (!seen[C[j] - 1]) {
                seen[C[j] - 1] = true;
                ps.emplace_back(j, C[j] - 1);
            }
        }
        int k = ps.size() - 1;
        
        int remaining = 0;
        priority_queue<pair<int, int>> pq; 
        for (int j = ans - 1; j >= 0; --j) {
            if (k >= 0 && ps[k].first == j) {
                if (A[ps[k].second] > 0) {
                    pq.emplace(-A[ps[k].second], ps[k].second);
                } else {
                    ++remaining;
                }
                --k;
            } else {
                ++remaining;
            }
            while (remaining < pq.size()) {
                pq.pop();
                ++remaining;
            }
        }
        
        ll needops = n;
        vector<int> cnt = A;
        while (!pq.empty()) {
            auto [negcnt, i] = pq.top();
            pq.pop();
            cnt[i] = 0;
            needops++;
        }
        needops += accumulate(cnt.begin(), cnt.end(), 0LL);
        return needops <= (ll)ans;
        return true;
    }
    
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        int lo = 1, hi = m + 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool okval = ok(nums, changeIndices, mid);
            if (okval) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo == m + 1 ? -1 : lo;
    }
};