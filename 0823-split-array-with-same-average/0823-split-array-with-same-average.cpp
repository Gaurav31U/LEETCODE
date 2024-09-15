class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        vector<set<int>> tmp(n/2+1);
        tmp[0].insert(0);
        for(auto num:nums)
            for(int i=n/2;i>=1;i--)
                for(auto it:tmp[i-1])
                    tmp[i].insert(it+num);
        
        int sum=0;
        for(auto it:nums)sum+=it;
        for(int i=1;i<=n/2;i++){
            if(i*sum%n==0){
                if(tmp[i].find(i*sum/n)!=tmp[i].end())return true;
            }
        }
        return false;
    }
};