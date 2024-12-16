class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>> pq;
        int i=0;
        for(auto it:nums){
            pq.push({-it,-(i++)});
        }
        vector<int> ans(nums.size(),0);
        for(int i=0;i<k;i++){
            auto tp=pq.top();
            pq.pop();
            pq.push({(tp.first*multiplier),tp.second});
        }
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            ans[-tp.second]=-tp.first;
        }
        return ans;
    }
};