class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans;
        int row=0;
        int col=0;
        vector<int> adj[501],ad[501];
        vector<int> ind(501,0),in(501,0);
        for(auto it:rowConditions){
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        for(auto it:colConditions){
            ad[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        map<int,int> mp1,mp2;;
        int c=0;
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        if(q.empty())return ans;
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            c++;
            mp1[tp]=row++;
            for(auto it:adj[tp]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(c!=k)return ans;
        c=0;
        for(int i=1;i<=k;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        if(q.empty())return ans;
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            c++;
            mp2[tp]=col++;
            for(auto it:ad[tp]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                }
            }
        }
        if(c!=k)return ans;
        ans=vector<vector<int>>(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[mp1[i]][mp2[i]]=i;
        }
        return ans;
    }
};