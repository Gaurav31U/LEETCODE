class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int g=numsDivide[0];
        for(int i=0;i<numsDivide.size();i++){
            g=__gcd(g,numsDivide[i]);
        }
        for(int i=0;i<nums.size();i++)if(g%nums[i]==0)return i;
        return -1;
    }
};