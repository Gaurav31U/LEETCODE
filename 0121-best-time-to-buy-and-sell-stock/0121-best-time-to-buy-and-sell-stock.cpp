class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        priority_queue<int> pq;
        for(int i=0;i<prices.size();i++){
            if(!pq.empty()){
                ans=max(ans,pq.top()+prices[i]);
            }
            pq.push(-prices[i]);
        }
        return ans;
    }
};