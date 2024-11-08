class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<long long> pq; 
        vector<pair<int,int>> temp;
        for(int i=0;i<profits.size();i++){
            temp.push_back({capital[i],profits[i]});
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(temp[i].first<=w){
                pq.push(temp[i].second);
            }else{
                if(pq.empty())return w;
                while(!pq.empty() && w<temp[i].first && k>0){
                    w+=pq.top();
                    pq.pop();
                    k--;
                }
                if(k==0)return w;
                if(w>=temp[i].first)
                pq.push(temp[i].second);
            }
            if(k==0)break;
        }
        while(!pq.empty() && k>0){
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};