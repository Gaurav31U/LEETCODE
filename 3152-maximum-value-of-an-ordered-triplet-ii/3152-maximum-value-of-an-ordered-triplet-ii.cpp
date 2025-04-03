class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        multiset<int> ms;
        priority_queue<int> pq;
        int n=nums.size();
        long long ans=-1;
        for(int i=0;i<n-2;i++)ms.insert(nums[i]);
        pq.push(nums.back());
        for(int i=n-2;i>0;i--){
            if(ms.empty())break;
            int p=*(--ms.end());
            ans=max(ans,1ll*(p-nums[i])*pq.top());
            pq.push(nums[i]);
            if(i>0)ms.erase(ms.find(nums[i-1]));
        }
        if(ans<0)return 0;
        return ans;
    }
};