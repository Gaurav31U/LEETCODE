class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        vector<array<int,3>> tmp;
        int n=mat.size(),m=mat[0].size();
        int cnt=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tmp.push_back({mat[i][j],i,j});
            }
        }
        sort(tmp.begin(),tmp.end(),greater<array<int,3>>());
        int dp[n][m];
        memset(dp,-1,sizeof(dp));
        int ans=1,f=0;
        vector<priority_queue<int>> row(n),col(m);
        vector<pair<int,int>> put_row,put_col;
        int last=tmp[0][0];
        for(auto it:tmp){
            int i=it[1],j=it[2];
            int val=it[0];
            if(last!=val){
                for(auto it:put_row)
                    row[it.first].push(it.second);
                for(auto it:put_col)
                    col[it.first].push(it.second);
                last=val;
                put_row.clear();
                put_col.clear();
            }
            int mx=0;
            if(!row[i].empty())mx=row[i].top();
            if(!col[j].empty())mx=max(col[j].top(),mx);
            dp[i][j]=max(dp[i][j],mx+1);
            put_row.push_back({i,dp[i][j]});
            put_col.push_back({j,dp[i][j]});
            ans=max(ans,dp[i][j]);
        }
        return ans;
    }
};