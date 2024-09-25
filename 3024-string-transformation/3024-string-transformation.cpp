long long power_mod(long long a, long long b, int q){
    if(b<2){
        if(b==1) return a%q;
        return 1;
    }
    long long temp=power_mod(a, b/2, q);
    if(b%2==0) return temp*temp%q;
    return temp*temp%q*a%q;
}
const int p=1e9+7;

class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        string ss=s+s;
        auto found1=ss.find(t);
        if(found1==std::string::npos) return 0;
        long long base=power_mod(s.size()-1, k, p);
        int diff=k%2==0? 1 : -1;
        base=(base-diff)*power_mod(s.size(), p-2, p)%p;
        auto found2=ss.find(t, found1+1);
        if(found2==std::string::npos){
            return base;
        }
        else if(found2-found1==s.size()){ 
            return (base+diff)%p;
        }
        else{
            int d=found2-found1;
            int ans_diff=found1==0? diff : 0;
            return (s.size()/d*base+ans_diff)%p;
        }
    }
};