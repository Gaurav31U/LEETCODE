class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        vector<int> freq(n+1,0);
        for(int i=0;i<(n-k+1);i++){
            if(freq[i]&1)nums[i]^=1;
            if(nums[i]==0){
                freq[i]++;
                freq[i+k]--;
                nums[i]^=1;
                ans++;
            }
            freq[i+1]+=freq[i];
        }
        for(int i=(n-k+1);i<n;i++){
            if(freq[i]&1)nums[i]^=1;
            freq[i+1]+=freq[i];
        }
        for(int i=0;i<n;i++)if(nums[i]==0)return -1;
        return ans;
    }
};