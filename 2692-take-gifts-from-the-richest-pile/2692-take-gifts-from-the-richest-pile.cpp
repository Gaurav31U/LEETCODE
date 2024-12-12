class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans=0;
        priority_queue<int> pq;
        for(auto it:gifts)pq.push(it);
        for(int i=0;i<k;i++){
            auto tp=pq.top();
            pq.pop();
            // ans+=sqrt(tp);
            pq.push(sqrt(tp));
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        // for(int i=k;i<gifts.size();i++)ans+=gifts[i];
        return ans;
    }
};