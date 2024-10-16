class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,int>> pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            if(tp.first>=2){
                if(ans.empty() || ans.back()!=tp.second){
                    ans+=char(tp.second);
                    tp.first--;
                }
                ans+=char(tp.second);
                tp.first--;
            }else{
                ans+=char(tp.second);
                tp.first-=1;
            }
            if(!pq.empty()){
                auto t=pq.top();
                pq.pop();
                if(t.first>=1){
                    ans+=char(t.second);
                    t.first-=1;
                }else break;
                if(t.first>0)pq.push(t);
            }else break;
            if(tp.first>0)pq.push(tp);
        }
        return ans;
    }
};