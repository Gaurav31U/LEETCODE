class Solution {
public:
    struct node {
        char lc = 0, rc = 0;
        int pref = 0, suf = 0, longest = 0, sz = 1;
        void merge(node &l, node &r) {
            longest = max(l.longest, r.longest);
            if (l.rc == r.lc)
                longest = max(longest, l.suf + r.pref);
            sz = l.sz + r.sz;
            lc = l.lc;
            rc = r.rc;
            pref = l.pref + (l.pref == l.sz && l.lc == r.lc ? r.pref : 0);
            suf = r.suf + (r.suf == r.sz && r.rc == l.rc ? l.suf : 0);
        } 
    };
    int st_set(vector<node>& st, int pos, char ch, int i, int l, int r) {
        if (l <= pos && pos <= r) {
            if (l != r) {
                auto m = l + (r - l) / 2, li = 2 * i + 1, ri = 2 * i + 2;
                st_set(st, pos, ch, li, l, m);
                st_set(st, pos, ch, ri, m + 1, r);
                st[i].merge(st[li], st[ri]);
            }
            else {
                st[i].lc = st[i].rc = ch;
                st[i].suf = st[i].pref = st[i].longest = 1;
            }
        }
        return st[i].longest;
    }    
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        vector<int> res;
        int powOf2 = 1, sz = s.size();
        while (powOf2 < sz) 
            powOf2 <<= 1;
        vector<node> st(powOf2 * 2);
        for (int i = 0; i < s.size(); ++i)
            st_set(st, i, s[i], 0, 0, powOf2 - 1);
        for (int j = 0; j < queryCharacters.size(); ++j)
            res.push_back(st_set(st, queryIndices[j], queryCharacters[j], 0, 0, powOf2 - 1));
        return res;
    }
};