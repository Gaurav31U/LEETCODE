class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        auto tmp=nums;
        sort(tmp.begin(),tmp.end());
        vector<int> val;
        int cnt=__builtin_popcount(nums[0]);
        vector<int> t;
        for(int i=0;i<nums.size();i++){
            int k=__builtin_popcount(nums[i]);
            if(k==cnt){
                t.push_back(nums[i]);
            }else{
                sort(t.begin(),t.end());
                for(auto it:t)val.push_back(it);
                cnt=k;
                t.clear();
                t.push_back(nums[i]);
            }
        }
        if(t.size()>0){
            sort(t.begin(),t.end());
            for(auto it:t)val.push_back(it);
        }
        return val==tmp;
    }
};