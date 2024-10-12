class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long s=0;
        for(int i=0;i<target.size();i++){
            s+=target[i];
            if(target[i]!=1)
            pq.push(target[i]);
        }
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            if(tp>=s)return false;
            s-=tp;
            if(tp<=s)return false;
            while(tp!=1){
                if(tp<=s)break;
                tp-=s;
            }
            if(tp>=1)s+=tp;
            if(tp>1)pq.push(tp);
        }
        return true;
    }
};