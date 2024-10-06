class Solution {
public:
    long long fact[100001];
    int mod=1e9+7;
    long long binpow(long long a,long long b){
        long long res=1;
        while(b>0){
            if(b&1){
                (res*=a)%=mod;
                b--;
            }else{
                (a*=a)%=mod;
                b>>=1;
            }
        }
        return res;
    }
    int countAnagrams(string s) {
        // Simple maths
        fact[0]=fact[1]=1;
        for(int i=2;i<=100000;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }
        long long ans=1;
        s+=' ';
        for(int i=0;i<s.size();){
            vector<int> f(128,0);
            int cnt=0;
            while(i<s.size() && s[i]!=' '){
                f[s[i]]++;
                i++;
                cnt++;
            }
            if(s[i]==' ')i++;
            long long tmp=fact[cnt];
            for(int j='a';j<='z';j++){
                if(f[j]>1){
                    (tmp*=binpow(fact[f[j]],mod-2))%=mod;
                }
            }
            (ans*=tmp)%=mod;
        }
        return ans;
    }
};