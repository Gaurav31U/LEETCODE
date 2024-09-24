class Solution {
public:
    long long maximumBeauty(vector<int>& fl, long long newFlowers, int target, int full, int partial) {
        sort(begin(fl), end(fl), greater<int>());
        long long p1 = 0, sum = 0, res = 0, sz = fl.size();
        for (; p1 < sz; ++p1) {
            if (target - fl[p1] > newFlowers)
                break;
            newFlowers -= max(0, target - fl[p1]);
        }
        if (p1 == sz)
            return max(sz * full, (sz - 1) * full + (fl.back() < target ? (long long)(target - 1) * partial : full));
        for (long long minF = fl.back(), p2 = fl.size() - 1; minF < target; ) {
            while (p2 >= p1 && fl[p2] <= minF)
                sum += fl[p2--];
            int needed = (sz - p2 - 1) * minF - sum;
            if (needed > newFlowers) {
                if (--p1 < 0)
                    break;
                newFlowers += max(0, target - fl[p1]);
            }
            else {
                res = max(p1 * full + minF * partial, res);    
                ++minF;
            }
        }
        return res;
    }
};