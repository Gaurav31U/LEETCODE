class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        if(start_node==end_node)return 1.0;
        double ans=0.0;
        vector<pair<int,double>> adj[10001];
        priority_queue<pair<double,int>> q;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        q.push({1.0,start_node});
        vector<double> pro(n+1,-1);
        pro[start_node]=1.0;
        while(!q.empty()){
            auto tp=q.top();
            q.pop();
            if(tp.second==end_node)return tp.first;
            for(auto it:adj[tp.second]){
                if(pro[it.first]<pro[tp.second]*it.second){
                    pro[it.first]=pro[tp.second]*it.second;
                    q.push({pro[it.first],it.first});
                }
            }
        }
        return ans;
    }
};