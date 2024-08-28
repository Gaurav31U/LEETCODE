class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans=0;
        stack<int> st;
        int n=nums.size();
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
            if(k>pre[i] && suf[i]>k)
            ans=max(ans,(suf[i]-pre[i]-1)*nums[i]);
        }
        return ans;
    }
};