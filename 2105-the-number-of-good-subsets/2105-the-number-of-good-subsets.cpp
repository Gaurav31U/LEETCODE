class Solution {
public:
    static const int mod=1e9+7;
    int binpow(long long a,long long b){
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
    int numberOfGoodSubsets(vector<int>& nums) {
        // bit manupilation
        map<int,int> mp,mask,bitmask;
        int prime[31];
        for(int i=0;i<=30;i++){
            prime[i]=i;
        }
        for(int i=2;i<=30;i++){
            if(prime[i]==i){
                for(int j=i*i;j<=30;j+=i)
                    prime[j]=i;
            }
        }
        int cnt=0;
        for(int i=2;i<=30;i++){
            if(prime[i]==i){
                mask[i]=(1<<cnt);
                cnt++;
            }
        }
        vector<int> tmp;
        for(int i=2;i<=30;i++){
            int num=i,c=0,val=0;
            while(num>1){
                int p=prime[num];
                val|=mask[p];
                int l=0;
                while(num%p==0){
                    num/=p;
                    l++;
                }
                if(l>1)c=1;
            }
            if(c==0){
                tmp.push_back(i);
                bitmask[i]=val;
            }
        }
        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)cnt++;
            if(bitmask.count(nums[i])){
                mp[bitmask[nums[i]]]++;
            }
        }
        long long ans=0;
        vector<pair<int,int>> vi;
        for(auto it:mp){
            vi.push_back({it.first,it.second});
        }
        int m=vi.size();
        for(int i=0;i<(1<<m);i++){
            int num=-1;
            int t=0;
            long long p=1;
            for(int j=0;j<m;j++){
                if( (i&(1<<j))>0 ){
                    if(num==-1){
                        num=vi[j].first;
                        (p*=vi[j].second)%=mod;
                        t++;
                    }else if((num&vi[j].first)==0){
                        num|=vi[j].first;
                        (p*=vi[j].second)%=mod;
                        t++;
                    }else{
                        p=0;
                        break;
                    }
                }
            }
            if(p!=0 && t>0)(ans+=p)%=mod;
        }
        (ans*=binpow(2,cnt))%=mod;
        // ans-=cnt;
        return ans;
    }   
};