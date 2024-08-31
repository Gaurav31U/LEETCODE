class FenwickTree {
    vector<array<int, 2>> tree;
public:
    FenwickTree(int n) : tree(n + 1) {}

    void update(int size, int op) {
        for (int i = tree.size() - size; i < tree.size(); i += i & -i) {
            tree[i][0] += op;
            tree[i][1] += op * size;
        }
    }

    pair<int, int> query(int size) {
        int cnt = 0, sum = 0;
        for (int i = tree.size() - size; i > 0; i &= i - 1) {
            cnt += tree[i][0];
            sum += tree[i][1];
        }
        return {cnt, sum};
    }
};

class Solution {
public:
    vector<int> numberOfAlternatingGroups(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size();
        set<int> s;
        FenwickTree t(n);
        auto update = [&](int i, int op) {
            auto it = s.lower_bound(i);
            int pre = it == s.begin() ? *s.rbegin() : *prev(it);
            int nxt = it == s.end() ? *s.begin() : *it;

            t.update((nxt - pre + n - 1) % n + 1, -op); 
            t.update((i - pre + n) % n, op);
            t.update((nxt - i + n) % n, op); 
        };

        auto add = [&](int i) {
            if (s.empty()) {
                t.update(n, 1);
            } else {
                update(i, 1);
            }
            s.insert(i);
        };

        auto del = [&](int i) {
            s.erase(i);
            if (s.empty()) {
                t.update(n, -1);
            } else {
                update(i, -1);
            }
        };

        for (int i = 0; i < n; i++) {
            if (a[i] == a[(i + 1) % n]) {
                add(i); 
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                if (s.empty()) {
                    ans.push_back(n); 
                } else {
                    auto [cnt, sum] = t.query(q[1]);
                    ans.push_back(sum - cnt * (q[1] - 1));
                }
            } else {
                int i = q[1];
                if (a[i] == q[2]) {
                    continue;
                }
                int pre = (i - 1 + n) % n, nxt = (i + 1) % n;
                if (a[pre] == a[i]) {
                    del(pre);
                }
                if (a[i] == a[nxt]) {
                    del(i);
                }
                a[i] ^= 1;
                if (a[pre] == a[i]) {
                    add(pre);
                }
                if (a[i] == a[nxt]) {
                    add(i);
                }
            }
        }
        return ans;
    }
};
