class Solution {
public:
    #define ll long long 
    ll pwr(ll b,ll n){
        ll ans = 1, mod = 1e9+7;
        for( ; n ; n>>=1){
            if(n&1)ans = (ans*b)%mod;
            b = (b*b)%mod;
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
    // stack on primes for finding nearest greater on both left and right 
        int n = nums.size();
        int N = 1e5+1;
        ll mod = 1e9 + 7;
        vector<int> pscore(N,0);
        for(ll i = 2; i < N; i++){
            if(pscore[i] != 0)continue;
            for(ll j = i; j < N; j+= i){
                pscore[j] += 1;
            }
        }
        vector<int> st;
        vector<int> left(n),right(n);
        for(int i = 0; i < nums.size(); i++){
            while(st.size() && pscore[nums[st.back()]] < pscore[nums[i]])st.pop_back();
            if(st.size())left[i] = st.back();
            else left[i] = -1;
            st.push_back(i);
        }
        while(st.size())st.pop_back();
        for(int i = n-1; ~i; i--){
            while(st.size() && pscore[nums[st.back()]] <= pscore[nums[i]])st.pop_back();
            if(st.size())right[i] = st.back();
            else right[i] = n;
            st.push_back(i);
        }
        vector<int> rorder(n);
        for(int i = 0; i < n; i++)rorder[i] = i;
        sort(begin(rorder),end(rorder),[&](const int &a,const int &b){return nums[a] > nums[b];});
        
        ll ans = 1;
        
        for(int i = 0; i < n; i++){
            ll idx = rorder[i];
        
            ll l = left[idx], r = right[idx];
            ll sub = (idx - l)*(r - idx);
            
            if(k > sub){
                ll res = pwr(nums[idx],sub);
                ans = (ans*res)%mod;
                k -= sub;
                
            }
            else{
                ll res = pwr(nums[idx],k);
                ans = (ans*res)%mod;
                return ans;
            }
        }
        return ans;
        
    }
};
