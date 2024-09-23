#define ll long long
#define MOD 1000000007
class Solution {
public: 
    ll ncr(ll n, ll r) {
        long long p = 1, k = 1;
        if (n - r < r)r = n - r;
        if (r != 0) {
            while (r) {
                p *= n;k *= r;
                long long m = __gcd(p, k);
                p /= m;k /= m;
                n--;r--;
            }
        }
        else p = 1;
        return p;
    }
    ll pow(ll n, ll q) {
        ll ans = n;
        while(--q) {
            ans = (ans*n)%MOD;
        }
        return ans;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.length();i++) {
            freq[s[i]]++;
        }
        if(freq.size() < k) return 0;
        map<int,int, greater<int>> mp;
        for(auto [key,val]: freq) {
            mp[val]++;
        }
        ll ans = 1;
        for(auto [score,freq]: mp) {
            if(freq <= k) {
                ll combination = pow(score,freq)%MOD;
                ans = (ans*combination)%MOD;
                k -= freq;
                if(!k) break;
            }else {
                ll grps = ncr(freq,k)%MOD;
                ll combination = pow(score,k)%MOD;
                ans = ans*((grps*combination)%MOD)%MOD;
                break;
            }
        }
        
        return ans;
    }

};