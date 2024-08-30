class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int line[2001] = {};
        sort(begin(tasks), end(tasks), [](const auto &t1, const auto &t2){
            return t1[1] < t2[1];
        });
        for (auto &t : tasks) {
            int st = t[0], end = t[1], d = t[2];
            d -= count(begin(line) + st, begin(line) + end + 1, true);
            for (int i = end; d > 0; --i) {
                d -= !line[i];
                line[i] = true;
            }
        }
        return count(begin(line), end(line), true);
    }
};