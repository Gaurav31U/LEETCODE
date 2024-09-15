class Solution {
public:
    int shortestSubarray(vector<int> arr, int K) {
        long long N = arr.size(), res = N + 1;
        deque<long long> d;
        vector<long long> A;
        for(auto it:arr)A.push_back(it);
        for (long long i = 0; i < N; i++) {
            if (i > 0)
                A[i] += A[i - 1];
            if (A[i] >= K)
                res = min(res, i + 1);
            while (d.size() > 0 && A[i] - A[d.front()] >= K)
                res = min(res, i - d.front()), d.pop_front();
            while (d.size() > 0 && A[i] <= A[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res <= N ? res : -1;
    }
};