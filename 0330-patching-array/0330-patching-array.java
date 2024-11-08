class Solution {
    public int minPatches(int[] nums, int n) {
        int ans=0,i=0;
        long sum=0;
        while(sum<n){
            if(i<nums.length && nums[i]<=sum+1){
                sum+=nums[i++];
            }else{
                sum+=(sum+1);
                ans++;
            }
        }
        return ans;
    }
}