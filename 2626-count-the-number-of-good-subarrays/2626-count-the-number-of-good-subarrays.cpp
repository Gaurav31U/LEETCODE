 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        long long cnt=0;
        int j=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int l=mp[nums[i]]++;

            cnt-=(l*(l-1))/2;
            l++;
            cnt+=(l*(l-1))/2;
            
            if(cnt>=k)ans+=(nums.size()-i);
            while(j< nums.size() && cnt>=k){
                
                l=mp[nums[j]]--;
                cnt-=(l*(l-1))/2;
                l--;
                cnt+=(l*(l-1))/2;
                j++;

                if(cnt>=k){
                    ans+=(nums.size()-i);
                }
            }
        }
        return ans;
    }
};