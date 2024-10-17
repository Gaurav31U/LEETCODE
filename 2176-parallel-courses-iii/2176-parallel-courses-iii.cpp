class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[50001];
        int ind[50001];
        memset(ind,0,sizeof(ind));
        for(auto it:relations){
            ind[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        for(int i=1;i<=n;i++)if(ind[i]==0)q.push({time[i-1],i});
        int s=0;
        while(!q.empty()){
            auto tp=q.top();
            q.pop();
            s=max(s,tp.first);
            for(auto it:adj[tp.second])
                if(--ind[it]==0)
                    q.push({tp.first+time[it-1],it}); 
        }    
        return s;
    }
};