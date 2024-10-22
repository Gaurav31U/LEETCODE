class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int t, int c) {
        using p=pair<int,int>;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> dis(n, vector<int>(2,INT_MAX));
        vector<vector<int>> g(n);
        for(auto i: edges){
            i[0]--;i[1]--;
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        pq.push({0,0});
        dis[0][0]=0;
        int turn =0;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int d=it.first;
            int s=it.second;
            if((d/c)%2!=0)d=c+(c*(d/c));
            int time=d;
            for(auto i: g[s]){
                if(dis[i][0]>time+t){
                    dis[i][0]=time+t;
                    pq.push({time+t,i});
                }else if(dis[i][1]>time+t || dis[i][1]==dis[i][0]){
                    dis[i][1]=time+t;
                    pq.push({time+t,i});
                }
            }
        }
        return dis[n-1][1];
        
        
        
    }
};