
 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    long long binpow(long long a,long long b,int md=1e9+7){
        long long res=1;
        while(b>0){
            if(b&1){
                (res*=a)%=md;
                b--;
            }else{
                (a*=a)%=md;
                b>>=1;
            }
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        int e=5,p=4;
        int md=1e9+7;
        if(n&1){
            return (binpow(e,n/2+1)*1ll*binpow(p,n/2))%md;
        }
        return (binpow(e,n/2)*1ll*binpow(p,n/2))%md;
    }
};