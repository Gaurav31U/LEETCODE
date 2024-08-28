static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
const int N=1e5+1;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long ans=0;
        vector<long long> sum;
        sum.push_back(nums[0]);
        stack<int> st;
        int n=nums.size();
        for(int i=1;i<n;i++){
            sum.push_back(sum.back()+nums[i]);
        }
        vector<int> suf(n,n);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() && nums[i]<=nums[st.top()]){
                    st.pop();
                }
                if(!st.empty())suf[i]=st.top();
                st.push(i);
            }
        }
        while(!st.empty())st.pop();
        vector<int> pre(n,-1);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }else{
                while(!st.empty() && nums[i]<=nums[st.top()]){
                    st.pop();
                }
                if(!st.empty())pre[i]=st.top();
                st.push(i);
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans, ( sum[suf[i]-1] - (pre[i]>-1?sum[pre[i]]:0) )*nums[i]);
        }
        int md=1e9+7;
        return ans%md;
    }
};