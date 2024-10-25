class Solution {
public:
    void fun(int a){
        if(a==0)return;
        fun(a>>1);
        cout<<(a&1)<<" ";
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        // fun(47);
        // cout<<"\n";
        // fun(39);
        for(int i=0;i<nums.size();i++){
            int p=nums[i]&(nums[i]+1);
            if(p==0){
                ans.push_back(nums[i]>>1);
                continue;
            }
            int s=p^(nums[i]);
            int c=(s>>1)|p;
            if((c|(c+1))==nums[i]){
                ans.push_back(c);
                continue;
            }
            int a=nums[i]&(nums[i]-1);
            if(a==0){
                ans.push_back(-1);

            }else{
                int b=a-1;
                if((b|(b+1))==nums[i])
                    ans.push_back(b);
                else ans.push_back(a);
            }
        }
        return ans;
    }
};