class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans="";
        sort(nums.begin(),nums.end(),[&](int a,int b){
            string s1=to_string(a)+to_string(b);
            string s2=to_string(b)+to_string(a);
            return stold(s1)>stold(s2);
        });
        for(auto it:nums)ans+=to_string(it);
        if(ans[0]=='0')return "0";
        return ans;
    }
};