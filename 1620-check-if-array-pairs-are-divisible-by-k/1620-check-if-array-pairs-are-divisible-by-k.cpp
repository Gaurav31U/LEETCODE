class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for(auto &it:arr){
            it=(it+100000000ll*k)%k;
        }
        map<int,int> mp;
        for(auto it:arr)mp[it]++;
        if(mp[0]%2!=0)return false;
        if(k%2==0 && (mp[k/2]&1))return false;
        for(int i=1;i<=k/2;i++){
            if(mp[i]!=mp[k-i])return false;
        }
        return true;
    }
};