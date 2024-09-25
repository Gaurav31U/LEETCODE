#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<pair<long long,int>, null_type,less<pair<long long,int>>, rb_tree_tag,tree_order_statistics_node_update> 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set st;
        int ans=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            ans+=(st.order_of_key({nums[i],0}));
            st.insert({2ll*nums[i],i});
        }
        return ans;
    }
};