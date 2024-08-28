class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        if(2*k+1>nums.size()){
            return vector<int>(nums.size(),-1);
        }
        if(k==0){
            return nums;
        }
        int n=nums.size();
        for(int i=0;i<k;i++)ans.push_back(-1);
        double sum=0;
        for(int i=0;i<min(n,2*k+1);i++){
            sum+=nums[i];
        }
        int j=0;
        for(int i=k;i<n-k;i++){
            ans.push_back(sum/(2*k+1));
            if(i+k+1<n)sum+=nums[i+k+1];
            sum-=nums[i-k];
        }
        for(int i=0;i<k;i++){
            if(ans.size()==n)break;
            ans.push_back(-1);
        }
        return ans;
    }
};