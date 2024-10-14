class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)pq.push(nums[i]);
        for(int i=0;i<k;i++){
            auto tp=pq.top();
            pq.pop();
            ans+=tp;
            tp=(tp+2)/3;
            pq.push(tp);
        }
        return ans;
    }
};