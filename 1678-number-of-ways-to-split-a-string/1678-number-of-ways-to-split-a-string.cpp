class Solution {
public:
    int numWays(string s) {
        int cnt=0;
        for(auto it:s)if(it=='1')cnt++;
        int mod=1e9+7;
        if(cnt==0){
            int n=s.size();
            return ((n-1)*1ll*(n-2)/2)%mod;
        }
        if(cnt%3!=0)return 0;
        long long ans=0;
        int c1=0,c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')c++;
            if(s[i]=='1' && c1>0)break;
            if(c==(cnt/3)){
                c1++;
            }
        }
        int c2=0;
        c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1')c++;
            if(s[i]=='1' && c2>0)break;
            if(c==(cnt/3))c2++;
        }
        return (c1*1ll*c2)%mod;
    }
};