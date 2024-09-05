class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        long long pow=1,cur=0,n=s.size(),res=0;
        for(int i=n-1;i>=0;i--){
            cur=(cur*power + (s[i]-'a'+1))%mod;
            if(i+k>=n){
                pow=(pow*power)%mod;
            }else{
                cur=(cur-(s[i+k]-'a'+1)*pow%mod+mod)%mod;
            }
            if(cur==hashValue)
                res=i;
        }
        return s.substr(res,k);
    }
};