class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0;i<group.size();i++){
            if(group[i]==-1)group[i]=m++;
        }
        map<int,vector<int>> mp;
        for(int i=0;i<group.size();i++)group[i]++;
        vector<int> adj[n+1];
        vector<int> adj1[m+1];
        vector<int> ind(n+1,0),in(m+1,0);

        map<pair<int,int>,int> grpedge;
        for(int i=0;i<beforeItems.size();i++){
            if(beforeItems[i].empty())continue;
            for(auto it:beforeItems[i]){
                adj[it].push_back(i);
                ind[i]++;
               
                if(group[i]!=group[it]){
                    if(grpedge.find({group[it],group[i]})!=grpedge.end())continue;
                    adj1[group[it]].push_back(group[i]);
                    in[group[i]]++;
                    grpedge[{group[it],group[i]}]++;
                }
            }
        }
        for(int i=0;i<group.size();i++){
            mp[group[i]].push_back(i);
        }
        int val=0;
        queue<int> q;
        map<int,int> item,grp;
        for(int i=0;i<n;i++){
            if(ind[i]==0)q.push(i);
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto tp=q.front();
                item[tp]=val++;
                q.pop();
                for(auto it:adj[tp]){
                    if(--ind[it]!=0)continue;
                    q.push(it);
                }
            }
        }
        if(val!=n)return {};
        val=0;
        for(int i=0;i<=m;i++){
            if(in[i]==0)q.push(i);
        }
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto tp=q.front();
                grp[tp]=val++;
                q.pop();
                for(auto it:adj1[tp]){
                    if(--in[it]!=0)continue;
                    q.push(it);
                }
            }
        }
        // cout<<val<<" "<<m;
        if(val!=(m+1))return {};
        vector<pair<int,int>> x;
        for(auto it:grp){
            x.push_back({it.second,it.first});
        }
        vector<int> ans;
        sort(x.begin(),x.end());
        for(auto it:x){
            vector<pair<int,int>> y;
            for(auto ti:mp[it.second]){
                y.push_back({item[ti],ti});
            }
            sort(y.begin(),y.end());
            for(auto ti:y)
                ans.push_back(ti.second);
        }
        if(ans.size()!=n)return {};
        return ans;

    }
};