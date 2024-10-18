class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx=0;
        for(auto it:nums)mx|=it;
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<=((1<<n)-1);i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    temp|=nums[j];
                }
            }
            if(temp==mx)cnt++;
        }
        return cnt;
    }
};