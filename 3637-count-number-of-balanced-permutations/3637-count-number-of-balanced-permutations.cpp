#define M 1000000007
#define ll long long
class Solution {
public:
    ll fact[85], invfact[85];
    ll pwr(ll a, ll b){
        if (b == 0)
            return 1;
        else if (b % 2 == 0){
            ll res = pwr(a, b / 2);
            return ((res % M) * (res % M)) % M;
        }else{
            ll res = pwr(a, (b - 1) / 2);
            return (((a * (res % M)) % M) * (res % M)) % M;
        }
    }
    ll halfSum = 0, halfCnt = 0, dp[15][85][725];
    ll bruteforce(ll freq[], ll ix, ll cnt, ll takeSum) {
        if(ix == 10 && takeSum == halfSum && cnt == halfCnt)
            return 1;
        else if(ix == 10 || takeSum > halfSum || cnt > halfCnt)
            return 0;

        if(dp[ix][cnt][takeSum] == -1){
            // take i amount
            ll ans = 0;
            for(ll i = 0; i <= freq[ix]; i++)
                ans = (ans + (invfact[i] * (invfact[freq[ix] - i] * bruteforce(freq, ix + 1, cnt + i, takeSum + ix * i) % M)) % M) % M;
            dp[ix][cnt][takeSum] = ans;
        }

        return dp[ix][cnt][takeSum];
    }

    void populate(){
        // pre compute factorial and inv factorial
        ll f = 1, inv;
        fact[0] = 1;
        for (ll i = 1; i <= 80; i++)
            f = (f * i) % M, fact[i] = f;

        f = 1, inv = 1;
        invfact[0] = 1;
        for (ll i = 1; i <= 80; i++)
            inv = pwr(i, M - 2) % M, f = (f * inv) % M, invfact[i] = f;
    }

    int countBalancedPermutations(string num) {
        populate();

        ll totalSum = 0, cnt = 0, freq[10] = {};
        for(auto it : num)
            totalSum += it - '0', freq[it - '0']++, cnt++;

        for(int i = 0; i <= 10; i++)
            for(int j = 0; j <= num.size(); j++)
                for(int k = 0; k <= totalSum; k++)
                    dp[i][j][k] = -1;
        
        if(totalSum % 2)
            return 0;

        halfSum = totalSum >> 1, halfCnt = cnt >> 1;
        ll ans = (bruteforce(freq, 0, 0, 0) * ((fact[cnt / 2] * fact[(cnt + 1) / 2]) % M)) % M;

        return ans;
    }
};