class Solution {
public:
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
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
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n=a.size(),m=b.size();
        a=a+'#'+s;b=b+'#'+s;
        auto A=prefix_function(a);
        auto B=prefix_function(b);
        vector<int> vi;
        for(int i=0;i<B.size();i++){
            if(B[i]==m){
                vi.push_back(i-2*m);
            }
        }
        vector<int> ans;
        for(int i=0;i<A.size();i++){
            if(A[i]==n){
                int idx=i-2*n;
                auto tp=lower_bound(vi.begin(),vi.end(),idx);
                int p=1;
                if(tp!=vi.end() && abs(*tp-idx)<=k){
                    ans.push_back(idx);p=0;
                }
                if(p && tp!=vi.begin() && abs(*(--tp)-idx)<=k){
                    ans.push_back(idx);
                }
            }
        }
        return ans;
    }
};