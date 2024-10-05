class Solution {
public:
    int m=1e9+7;
    long long binpow(long a,long b){
        long long res=1;
        while(b>0){
            if(b&1){
                (res*=a)%=m;
                b--;
            }else{
                (a*=a)%=m;
                b>>=1;
            }
        }
        return res;
    }
    int maxNiceDivisors(int n) {
        if(n==1)return 1;
        if(n%3==0)return binpow(3,n/3);
        if(n%3==1)return (4*binpow(3,n/3-1))%m;
        return (2*binpow(3,n/3))%m;
    }
};