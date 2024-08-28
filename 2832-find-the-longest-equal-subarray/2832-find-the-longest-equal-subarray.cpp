static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        if(nums.size()==1)return 1;
        int ans=0;
        int l=1,r=nums.size();
        vector<int> freq(nums.size()+1,0);
        while(l<=r){
            int mid=(l+r)/2;
            int len=0;
            bool found=false;
            vector<int> mp(1e5+1,0);
            int c=0;
            for(int i=0;i<mid;i++){
                freq[mp[nums[i]]]--;
                mp[nums[i]]++;
                c=max(mp[nums[i]],c);
                freq[mp[nums[i]]]++;
            }
            if(mid-c<=k){
                found=true;
                len=max(len,c);
            }
            for(int i=mid;i<nums.size();i++){
                freq[mp[nums[i-mid]]]--;
                if(c==mp[nums[i-mid]]){
                    if(freq[mp[nums[i-mid]]]==0)c--;
                }
                mp[nums[i-mid]]--;
                freq[mp[nums[i-mid]]]++;

                freq[mp[nums[i]]]--;
                mp[nums[i]]++;
                c=max(c,mp[nums[i]]);
                freq[mp[nums[i]]]++;

                if(mid-c<=k){
                  found=true;
                  len=max(len,c);
                }

            }
            if(found){
                ans=max(ans,len);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};