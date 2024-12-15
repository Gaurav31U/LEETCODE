class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<classes.size();i++){
            double tmp=double(classes[i][0]+1)/(classes[i][1]+1);
            tmp-=double(classes[i][0])/(classes[i][1]);
            pq.push({tmp,i});
        } 
        while(ex>0){
            auto tp=pq.top();
            pq.pop();
            ex--;
            int i=tp.second;
            classes[i][0]++;
            classes[i][1]++;
            double tmp=double(classes[i][0]+1)/(classes[i][1]+1);
            tmp-=double(classes[i][0])/(classes[i][1]);
            pq.push({tmp,i});
        }
        double ans=0;
        for(auto it:classes){
            ans+=double(it[0])/it[1];
        }
        ans/=classes.size();
        return ans;
    }
};